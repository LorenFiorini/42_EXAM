
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

enum e_error {
	ERROR_CD_BAD_ARGS = 0,
	ERROR_CD_CHDIR,
	ERROR_FATAL,
	ERROR_EXECVE
};

static int	ft_strlen(char *str) {
	int i = 0;
	while (*(str + i)) {
		i++;
	}
	return (i);
}

static void	print_error(int error_type, char *str) {
	char	*error_msg[5] = {
		"error: cd: bad arguments",
		"error: cd: cannot change directory to ",
		"error: fatal",
		"error: cannot execute ",
		NULL
	};
	// printf("%s\n", error_msg[error_type]);
	write(STDERR_FILENO, error_msg[error_type], ft_strlen(error_msg[error_type]));
	if (str) {
		write(STDERR_FILENO, str, ft_strlen(str));
	}
	write(STDERR_FILENO, "\n", 1);
	if (error_type >= ERROR_FATAL) {
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int fd[3];

	fd[2] = dup(0);

	// printf("argc = %i\n", argc);
	int i = 1;
	while (i < argc) {
		char **command = argv + i;
		
		while (argv[i] != NULL && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		{	
			// printf("argv[%i] = %s\n", i, argv[i]);
			i++;
		}
		// printf("---> argv[%i] = %s\n", i, argv[i]);
		if (strcmp(command[0], "cd") == EXIT_SUCCESS) {					// strcmp(argv[i], "cd")	or	strcmp(command, "cd")
			if (*(argv + i - 2) != *(command)) {			// strcmp(argv[i], command[2]) != EXIT_SUCCESS	or	(argv + i) != (command + 2) 
				// printf("Bad argument\n");
				// printf("command: %s != %s \n", *argv + i - 2, *command);
				print_error(ERROR_CD_BAD_ARGS, NULL);
			} else if (chdir(command[1]) != EXIT_SUCCESS) {
				// printf("Cannot change directory");
				print_error(ERROR_CD_CHDIR, argv[i - 1]);
			} else {
				// printf("It changed\n");
			}
		} else if ((argv + i) != (command) && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) {
			if (fork() == 0) {
				// printf("; child\n");
				dup2(fd[2], 0);
				close(fd[2]);
				argv[i] = NULL;
				execve(command[0], command, envp);
				print_error(ERROR_EXECVE, command[0]);
				// exit(1);
			} else {
				// printf("; parent\n");
				close(fd[2]);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				fd[2] = dup(0);
			}
		} else if ((argv + i) != (command) && strcmp(argv[i], "|") == 0) {
			pipe(fd);
			if (fork() == 0) {
				// printf("| child\n");
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
				dup2(fd[2], 0);
				close(fd[2]);
				argv[i] = NULL;
				execve(command[0], command, envp);
				print_error(ERROR_EXECVE, command[0]);
				// exit(1);
			} else {
				// printf("| parent\n");
				close(fd[2]);
				close(fd[1]);
				fd[2] = fd[0];
			}
		}
		i++;
	}
	// printf("while finished");
	close(fd[2]);
	return (0);
}
