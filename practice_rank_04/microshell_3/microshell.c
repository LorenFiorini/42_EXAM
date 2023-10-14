
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_argv(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	// print_argv(argv);
	int i = 0;
	int fd[3];

	fd[2] = dup(0);
	(void)argc;
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") != 0 && strcmp(argv[i], "|") != 0)
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				write(2, "error: cd: bad arguments\n", 25);
			else if (chdir(argv[1]) != 0) {
				write(2, "error: cd: cannot change directory to ", 38);
				write(2, argv[1], strlen(argv[1]));
				write(2, "\n", 1);
			}
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				argv[i] = NULL; 											// argv[i] = NULL in child process
				dup2(fd[2], 0);
				close(fd[2]);
				execve(argv[0], argv, envp);
				write(2, "error: cannot execute ", 22);
				write(2, argv[0], strlen(argv[0]));
				write(2, "\n", 1);
				exit(1);
			}
			else
			{
				close(fd[2]);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				fd[2] = dup(0);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				argv[i] = NULL; 											// argv[i] = NULL in child process
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
				dup2(fd[2], 0);
				close(fd[2]);
				execve(argv[0], argv, envp);
				write(2, "error: cannot execute ", 22);
				write(2, argv[0], strlen(argv[0]));
				write(2, "\n", 1);
				exit(1);
			}
			else
			{
				close(fd[1]);
				close(fd[2]);
				fd[2] = fd[0];
			}
		
		}
	}
	close(fd[2]);
	return (0);
}
