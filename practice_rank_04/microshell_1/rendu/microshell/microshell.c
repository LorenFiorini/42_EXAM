
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int ft_strlen(char *str) {
	int i = 0;
	
	while (str) {
		str++;
		i++;
	}
	return (i);
}

int cd(char **argv, int i)
{
	char *error_arg = "error: cd: bad arguments\n";
	char *error_dir = "error: cd: cannot change directory to ";

	if (i != 2) {
		write(2, error_arg, ft_strlen(error_arg));
		return (1);
	} else if (chdir(argv[1]) == -1) {
		write(2, error_dir, ft_strlen(error_dir));
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "n", 1);
		return (1);
	}
	return (0);
}

int exec(char **argv, char **envp, int i) {
	char *error_fatal = "error: fatal\n";
	char *error_exe = "error: cannot execute ";
	int fd[2];
	int status;
	int has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (has_pipe && pipe(fd) == -1) {
		write(2, error_fatal, ft_strlen(error_fatal));
		return (1);
	}
	
	int pid = fork();
	if (!pid) {
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)) {
			write(2, error_fatal, ft_strlen(error_fatal));
			return (1);
		}
		execve(*argv, argv, envp);
		write(2, error_exe, ft_strlen(error_exe));
		write(2, *argv, ft_strlen(*argv));
		write(2, "\n", 1);
		return (1);
	}

	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)) {
		write(2, error_fatal, ft_strlen(error_fatal));
		return (1);
	}
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
	int status = 0, i = 0;

	if (argc > 1) {
		while (argv[i] && argv[i + 1]) {
			argv += i + 1;
			i = 0;

			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";")) {
				i++;
			}
			if (!strcmp(*argv, "cd")) {
				status = cd(argv, i);
			} else if (i) {
				status = exec(argv, envp, i);
			}
		}
	}
	return (status);
}
