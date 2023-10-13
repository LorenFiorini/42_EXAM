
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_CD_BAD_ARGS "error: cd: bad arguments"
#define ERROR_CD_CANNOT_CHANGE_DIR "error: cd: cannot change directory to" // " path_to_change"
#define ERROR_FATAL "error: fatal"
#define ERROR_EXECVE "error: cannot execute" // " executable_that_failed"

void	ft_putstr(char *str);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
void	error_message(char *msg, int with_endline, int is_exit);
void	free_command(char *command);
char	**get_command(char **argv, int l, int r);

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strdup(char *src)
{
	int word_size = ft_strlen(src);
	char *str = (char *) malloc(sizeof(char) * (word_size + 1));
	
	int i = 0;
	while (src[i]) {
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return str;
}

void	error_message(char *msg, int with_endline, int is_exit)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (with_endline)
	{
		write(STDERR_FILENO, "\n", 1);
	}
	if (is_exit)
	{
		exit(1);
	}
}


char	**get_command(char **argv, int l, int r)
{
	char **command = (char **) malloc(sizeof(char *) * (r - l + 1));
	int i = 0;

	while (l + i < r)
	{
		command[i] = ft_strdup(argv[l + i]);
		i++;
	}
	command[i] = NULL;
	return (command);
}

void	free_command(char *command)
{

}

int	main(int argc, char **argv, char **envp)
{
	int l = 1, r = 1;

	pid_t pid;
	int fd[3] = {0,0,0};
	char **command;

	
	while (r <= argc)
	{
		int is_pipe = (strcmp(argv[r], "|") == 0);
		int is_semicolon = (strcmp(argv[r], ";") == 0);
		if (!argv[r] || is_pipe || is_semicolon)
		{
			int len = r - l;
			command = get_command(argv, l, r);
			if (strcmp(command[0], "cd") == 0) {
				if (len < 2) {
					error_message(ERROR_CD_BAD_ARGS, 1, 0);
				} else if (chdir(command[1])) {
					error_message(ERROR_CD_CANNOT_CHANGE_DIR, 0, 0);
					error_message(command[1], 1, 0);
				}
			} else {
				// Execute command
				if (is_pipe && pipe(fd) < 0)
					error_message(ERROR_FATAL, 1, 1);

				int tmp = fd[2];
				fd[2] = fd[0];
				fd[0] = tmp;

				pid = fork();
				if (pid < 0) {
					error_message(ERROR_FATAL, 1, 1);
				} else if (pid == 0) {
					if (fd[1] && dup2(fd[1], 1)) 
						error_message(ERROR_FATAL, 1, 1);
					if (fd[0] && dup2(fd[0], 0)) 
						error_message(ERROR_FATAL, 1, 1);
					if (execve(command[0], command, envp) < 0) {
						error_message(ERROR_EXECVE, 0, 0);
						error_message(command[0], 1, 1);
					}

				} else {
					int status;
					waitpid(pid, &status, 0);
					if (fd[0]) {
						close(fd[0]);
						fd[0] = 0;
					}
					if (fd[1]) {
						close(fd[1]);
						fd[1] = 0;
					}
					if (fd[2]) {
						close(fd[2]);
						fd[2] = 0;
					}
					if (WIFEXITED(status))
						exit(status);
				}
			}
			
		}
		if (!argv[r]) break;
		r++;
	}
	return (0);
}


/*
// Checking Arguments
int	main(int argc, char **argv, char **envp)
{
	(void)envp;
	int i = 0;
	int j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

*/