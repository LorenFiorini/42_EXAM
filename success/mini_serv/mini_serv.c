#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
    int id;
    char msg[300000];
} t_client;

void error_exit(char *str) {
    if (!str) {
        str = "Fatal error\n";
    }
    write(2, str, strlen(str));
    exit(1);
}

void send_broadcast(int except, int mxfd, char *buf, fd_set wst) {
    for (int fd = 0; fd <= mxfd; fd++) {
        if (FD_ISSET(fd, &wst) && fd != except) {
            if (send(fd, buf, sizeof(buf), 0) == -1) {
                error_exit(NULL);
            }
        }
    }
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        error_exit("Wrong number of arguments\n");
    }
    t_client    clients[1024];
    fd_set      rst, wst, cur;
    char        sendbuf[300000], recvbuf[300000];
    struct sockaddr_in address;
    socklen_t       len = sizeof(address);

    int serverfd = socket(PF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
        error_exit(NULL);
    }
    int mxfd = serverfd, gid = 0;

    FD_ZERO(&cur);
    FD_SET(serverfd, &cur);
    bzero(clients, sizeof(clients));
    bzero(&address, sizeof(address));
    address.sin_family = PF_INET;
    address.sin_addr.s_addr = htonl(0);
    address.sin_port = ntohs(atoi(argv[1]));

    if (bind(serverfd, (const struct sockaddr *) &address, len) == -1) error_exit(NULL);
    if (listen(serverfd, 1) == -1) error_exit(NULL);

    while (1) {
        rst = wst = cur;
        if (select(mxfd + 1, &rst, &wst, NULL, NULL) < 0) {
            error_exit(NULL);
        }
        for (int fd = 0; fd <= mxfd; fd++) {
            if (FD_ISSET(fd, &rst)) {
                if (fd == serverfd) {
                    int clientfd = accept(serverfd, (struct sockaddr *)& address, &len);
                    if (clientfd < 0) continue;
                    if (mxfd < clientfd) mxfd = clientfd;
                    clients[clientfd].id = gid; gid++;
                    FD_SET(clientfd, &cur);
                    sprintf(sendbuf, "server: client %d just arrived\n", clients[clientfd].id);
                    send_broadcast(clientfd, mxfd, sendbuf, cur);
                } else {
                    int ret = recv(fd, recvbuf, sizeof(recvbuf), 0);
                    if (ret >= 0) {
                        int j = strlen(clients[fd].msg);
                        for (int i = 0; i < ret; i++, j++) {
                            clients[fd].msg[j] = recvbuf[i];
                            if (clients[fd].msg[j] == '\n') {
                                clients[fd].msg[j] = '\0';
                                sprintf(sendbuf, "client %d: %s", clients[fd].id, clients[fd].msg);
                                send_broadcast(fd, mxfd, sendbuf, cur);
                                j = -1;
                            }
                        }
                    } else {
                        sprintf(sendbuf, "server: client %d just left\n", clients[fd].id);
                        send_broadcast(fd, mxfd, sendbuf, cur);
                        FD_CLR(fd, &cur);
                        close(fd);
                        bzero(clients[fd].msg, sizeof(clients[fd].msg));
                    }
                }
                break;
            }
        }
    }
    
    return 0;
}