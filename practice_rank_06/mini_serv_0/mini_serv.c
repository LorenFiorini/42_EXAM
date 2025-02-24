#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
    int     id;
    char    msg[100000];
}   t_client;

t_client    clients[1024];
fd_set      read_set;
fd_set      write_set;
fd_set      current;
char        send_buffer[120000];
char        recv_buffer[120000];

void serv_error(char  *msg) {
    write(2, msg, strlen(msg));
    exit(1);
}

void send_to_all(int except, int mxfd) {
    for (int fd = 0; fd <= mxfd; fd++) {
        if (FD_ISSET(fd, &write_set) && fd != except) {
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1) {
                serv_error("Fatal error\n");
            }
        }
    }
}

int     main(int argc, char **argv) {
    struct sockaddr_in  serveraddr;
    socklen_t           len;
    int                 serverfd;
    int                 mxfd;
    int                 gid = 0;

    if (argc != 2) {
        serv_error("Wrong number of arguments\n");
    }

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    mxfd = serverfd;
    if (serverfd == -1) {
        serv_error("Fatal error\n");
    }

    FD_ZERO(&current);
    FD_SET(serverfd, &current);
    bzero(clients, sizeof(clients));
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1) {
        serv_error("Fatal error\n");
    }

    while (1) {
        read_set = write_set = current;
        if (select(mxfd + 1, &read_set, &write_set, 0, 0) == -1) {
            continue;
        }

        for (int fd = 0; fd <= mxfd; fd++) {
            if (FD_ISSET(fd, &read_set)) {
                if (fd == serverfd) {
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
                    if (clientfd == -1) {
                        continue;
                    }
                    if (clientfd > mxfd) {
                        mxfd = clientfd;
                    }
                    clients[clientfd].id = gid++;
                    FD_SET(clientfd, &current);
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
                    send_to_all(clientfd, mxfd);
                } else {
                    int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
                    if (ret <= 0) {
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        send_to_all(fd, mxfd);
                        FD_CLR(fd, &current);
                        close(fd);
                    } else {
                        for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++) {
                            clients[fd].msg[j] = recv_buffer[i];
                            if (clients[fd].msg[j] == '\n') {
                                clients[fd].msg[j] = '\0';
                                sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                                send_to_all(fd, mxfd);
                                bzero(clients[fd].msg, strlen(clients[fd].msg));
                                j = -1;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    return (0);
}
