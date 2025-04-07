#include <stdio.h>
/*   */

#include <stdlib.h>
/*  atoi */

#include <unistd.h>
/*  write, close, select */

#include <string.h>
/*  strlen, bzero */

#include <sys/socket.h>
/*  socket */

#include <netinet/in.h>
/* Internet address family */

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
    int     mxfd = 0, gid = 0, servfd = 0;
    struct sockaddr_in  serveraddr;
    socklen_t           len;

    servfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 
    socket(domain, type, protocol);
      it creates a socket and returns its file descriptor 
    AF_INET
      address family IPV4
    SOCK_STREAM
      Specifies TCP (Transmission Control Protocol)
    0
      to automatically choose the protocol based on the socket type
    */
    if (servfd == -1) {
        error_exit(NULL);
    }

    FD_ZERO(&curfds);
    FD_SET(servfd, curfds);

    bzero(clients, sizeof(clients));
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port  = htons(atoi(argv[1]));
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    /* INADDR_ANY: A constant that tells the server to bind to any available network interface */

    return (0);
}
