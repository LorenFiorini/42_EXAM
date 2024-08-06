#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client {
    int     id;
    char    msg[300000];
}   t_client;



void    err(char  *msg)
{
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error", strlen("Fatal error"));
    write(2, "\n", 1);
    exit(1);
}

void    send_to_all(int except, int maxfd, fd_set write_set, char *send_buffer)
{
    for (int fd = 0; fd <= maxfd; fd++) {
        if  (FD_ISSET(fd, &write_set) && fd != except) {
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1) {
                err(NULL);
			}
		}
    }
}

int     main(int argc, char **argv)
{
	t_client			clients[1024];
	fd_set		        read_set, write_set, current;
	int         		maxfd = 0, gid = 0, serverfd = 0;
	char        		send_buffer[300000], recv_buffer[300000];
    struct sockaddr_in  serveraddr;
    socklen_t           len;


    if (argc != 2) {
        err("Wrong number of arguments");
	}
	serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) {
		err(NULL);
	}

    FD_ZERO(&current);
    FD_SET(serverfd, &current);
    bzero(clients, sizeof(clients));
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1) {
        err(NULL);
	}

    maxfd = serverfd;
    while (1) {
        read_set = write_set = current;
        if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1) continue;

        for (int fd = 0; fd <= maxfd; fd++) {
            if (FD_ISSET(fd, &read_set)) {
                if (fd == serverfd) {
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);

                    if (clientfd == -1) {
						continue;
					} else if (clientfd > maxfd) {
						maxfd = clientfd;
					}
                    clients[clientfd].id = gid++;
                    FD_SET(clientfd, &current);
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
                    send_to_all(clientfd, maxfd, current, send_buffer);
                } else {
                    int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
                    if (ret <= 0) {
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        send_to_all(fd, maxfd, current, send_buffer);
                        FD_CLR(fd, &current);
                        close(fd);
                        bzero(clients[fd].msg, strlen(clients[fd].msg));
                    } else {
                        for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++) {
                            clients[fd].msg[j] = recv_buffer[i];
                            if (clients[fd].msg[j] == '\n') {
                                clients[fd].msg[j] = '\0';
                                sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                                send_to_all(fd, maxfd, current, send_buffer);
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