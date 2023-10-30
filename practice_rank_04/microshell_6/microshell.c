

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


size_t	ft_strlength(char *str) {
	size_t i = 0;
	while (str[i]) {
		i++;
	}
	return (i);
}

void	write_to_stderr(char *str) {
	write(STDERR_FILENO, str, ft_strlength(str));
}

int main(int argc, char **argv, char **envp)
{
	// (void)argc;
	char	**cmd;
	int		i = 1;
	int		fd[3];

	fd[2] = dup(STDIN_FILENO);

	while (i < argc && argv[i]) {
		cmd = &argv[i];
		printf("cmd: %s\n", cmd[0]);	// DEBUG
		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0) {
			i++;
			printf("argv[%d]: %s\n", i, argv[i]);	// DEBUG
		}

		if (strcmp(cmd[0], "cd") == 0) {
			if (cmd[0] != argv[i - 2]) {
				write_to_stderr("error: cd: bad arguments\n");
			} else if (chdir(argv[i - 1]) != 0) {
				write_to_stderr("error: cd: cannot change directory to ");
				write_to_stderr(argv[i - 1]);
				write_to_stderr("\n");
			} else {
				write(1, "S\n", 2);
			}
		} else if (argv[i] && strcmp(argv[i], "|") == 0) {
			if (pipe(fd)) {
				write_to_stderr("error: fatal\n");
				exit(1);
			}
			int tmp = fd[0];
			fd[0] = fd[2];
			fd[2] = tmp;

			int pid = fork();
			if (pid == 0) {
				// Child
				argv[i] = NULL;
				dup2(STDIN_FILENO, fd[0]);
				close(fd[0]);
				dup2(STDOUT_FILENO, fd[1]);
				close(fd[1]);
				execve(cmd[0], cmd, envp);

				write_to_stderr("error: cannot execute ");
				write_to_stderr(cmd[0]);
				write_to_stderr("\n");
				exit(1);
			} else if (pid > 0) {
				// Parent
				close(fd[0]);
				close(fd[1]);
				while (waitpid(-1, NULL, WUNTRACED) == -1)
					;

			} else {
				// Failed fork 
				write_to_stderr("error: fatal\n");
				exit(1);
			}
		} else if (!argv[i] || strcmp(argv[i], ";") == 0) {
			int pid = fork();
			if (pid == 0) {
				// Child
				argv[i] = NULL;
				dup2(STDIN_FILENO, fd[0]);
				close(fd[0]);
				dup2(STDOUT_FILENO, fd[1]);
				close(fd[1]);
				// close(fd[2]);
				execve(cmd[0], cmd, envp);

				write_to_stderr("error: cannot execute ");
				write_to_stderr(cmd[0]);
				write_to_stderr("\n");
				exit(1);
			} else if (pid > 0) {
				// Parent
				close(fd[0]);
				close(fd[1]);
				close(fd[2]);
				fd[2] = dup(STDIN_FILENO);
			} else {
				// Failed fork 
				write_to_stderr("error: fatal\n");
				exit(1);
			}
		}
	}
	close(fd[2]);
	return (0);
}

/**
 * @brief Errors to STDERR
 * 
 * "error: cd: bad arguments"
 * "error: cd: cannot change directory to path_to_change"
 * "error: fatal"
 * "error: cannot execute executable_that_failed"
 */
