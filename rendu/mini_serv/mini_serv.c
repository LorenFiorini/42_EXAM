
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>

#define WRONG_NB_ARGS "Wrong number of arguments\n"
#define FATAL_ERROR "Fatal error\n"


typedef struct s_client {
	int					fd;
	char				buffer[4096];
	struct sockaddr_in	addr;
} t_client;


/* Global variables */

// fd_set		except_set, master_set;
fd_set		read_set;
fd_set		write_set;
fd_set		current;
t_client	clients[1024];
char		send_buffer[4096];
char		recv_buffer[4096];


/* Main */

int main(int argc, char ** argv) {
	if (argc != 2) {
		write(2, WRONG_NB_ARGS, strlen(WRONG_NB_ARGS));
		return 1;
	}

	struct sockaddr_in addr;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		write(2, FATAL_ERROR, strlen(FATAL_ERROR));
		return 1;
	}

	int max_fd = sockfd;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
		write(2, FATAL_ERROR, strlen(FATAL_ERROR));
		return 1;
	}
	if (listen(sockfd, 42) == -1) {
		write(2, FATAL_ERROR, strlen(FATAL_ERROR));
		return 1;
	}

	FD_ZERO(&current);
	FD_SET(sockfd, &current);
	bzero(&addr, sizeof(addr));
	bzero(&read_set, sizeof(read_set));
	while (1) {
		read_set = write_set = current;

		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) == -1) {
			write(2, FATAL_ERROR, strlen(FATAL_ERROR));
			return 1;
		}
		for (int i = 0; i <= max_fd; i++) {
			if (FD_ISSET(i, &read_set)) {
				if (i == sockfd) {
					int new_fd = accept(sockfd, (struct sockaddr *)&addr, (socklen_t *)&addr);
					if (new_fd == -1) {
						write(2, FATAL_ERROR, strlen(FATAL_ERROR));
						return 1;
					}
					if (new_fd > max_fd) {
						max_fd = new_fd;
					}
					FD_SET(new_fd, &current);
				} else {
					int ret = read(i, recv_buffer, 4096);
					if (ret == -1) {
						write(2, FATAL_ERROR, strlen(FATAL_ERROR));
						return 1;
					}
					if (ret == 0) {
						close(i);
						FD_CLR(i, &current);
					} else {
						for (int j = 0; j <= max_fd; j++) {
							if (FD_ISSET(j, &current) && j != sockfd && j != i) {
								write(j, recv_buffer, ret);
							}
						}
						break;
					}
				}
			}
		}
	}
	return 0;
}
