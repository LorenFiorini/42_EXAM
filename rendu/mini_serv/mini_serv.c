
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

void ft_putstr_fd(char *str, int fd)
{
	write(fd, str, strlen(str));
}

int main(int argc, char **argv) {
	if (argc != 2) {
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (1);
	}

	return (0);
}
