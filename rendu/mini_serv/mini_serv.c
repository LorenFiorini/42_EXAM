
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// #define ERR_ARG_NUM_ENDL "Wrong number of arguments\n"
// #define ERROR_FATAL_ENDL "Fatal error\n"



int main(int argc, char ** argv) {
	char * error_arg = "Wrong number of arguments\n";
	char * error_fatal = "Fatal error\n";
	if (argc != 2) {
		write(2, error_arg, strlen(error_arg));
		exit(1);
	}
	return (0);
}


/*

write
close
select
socket
accept
listen
send
recv
bind
strstr

malloc
realloc
free
calloc
bzero
atoi
sprintf
strlen
exit
strcpy
strcat
memset

*/
