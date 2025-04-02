#include <stdio.h>
// 
#include <stdlib.h>
// atoi
#include <unistd.h>
// write, close, select
#include <string.h>
// strlen, bzero
#include <sys/socket.h>

/* Macros */

# define MX_BUF 300000


/*  */

typedef struct s_client {
    int     id;
    char    msg[MX_BUF];
}   t_client;


void    error_exit(char *msg) {
    if (!msg) {
        msg = "Fatal error\n";
    }
    write(1, msg, strlen(msg));
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        error_exit("Wrong number of arguments\n");
    }
    t_client clients[1024];
    fd_set  readfds, writefds, curfds;
    char    send_buf[MX_BUF], recv_buf[MX_BUF];
    int     max_fd = 0, gid = 0, serv_fd = 0;
    struct sockaddr_in  server

    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_ZERO(&curfds);


    return 0;
}
