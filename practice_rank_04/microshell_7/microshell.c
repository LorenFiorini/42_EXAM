
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

size_t  len(char *a) {
    size_t i = 0;
    while (a[i]) {
        i++;
    }
    return (i);
}

void ms_error(char *a, char *b) {
    if (a)
        write(STDERR_FILENO, a, len(a));
    if (b)
        write(STDERR_FILENO, b, len(b));
    write(STDERR_FILENO, "\n", 1);
}

int main(int argc, char **argv, char **envp) {
    int i = 1;
    int fd[3];

    fd[2] = dup(0);
    while (i < argc && argv[i]) {
        char **cmd = &argv[i];
        while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
            i++;
        if (argv[i] && cmd == argv + i) {
            i++;
            continue;
        }
        if (strcmp(cmd[0], "cd") == 0) {
            if (cmd != (argv + i - 2))
                ms_error("error: cd: bad arguments", NULL);
            else if (chdir(cmd[1])) 
                ms_error("error: cd: cannot change directory to ", cmd[1]);
        } else if (argv[i] && strcmp(argv[i], "|") == 0) {
            pipe(fd);
            int t = fd[2];
            fd[2] = fd[0];
            fd[0] = t;
            int id = fork();
            if (id > 0) {
                close(fd[0]);
                close(fd[1]);
            } else if (id == 0) {
                argv[i] = NULL;
                close(fd[2]);
                dup2(fd[0], 0);
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);

                execve(cmd[0], cmd, envp);
                ms_error("error: cannot execute ", cmd[0]);
                exit(1);
            } else {
                ms_error("error: fatal", NULL);
                exit(EXIT_FAILURE);
            }
        } else if (!argv[i] || strcmp(argv[i], ";") == 0) {
            int id = fork();
            if (id > 0) {
                close(fd[2]);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                fd[2] = dup(0);
            } else if (id == 0) {
                argv[i] = NULL;
                dup2(fd[2], 0);
                close(fd[2]);

                execve(cmd[0], cmd, envp);
                ms_error("error: cannot execute ", cmd[0]);
                exit(1);
            } else {
                ms_error("error: fatal", NULL);
                exit(EXIT_FAILURE);
            }
        }
        if (!argv[i]) break;
        i++;
    }
    close(fd[2]);
    return (0);
}

/*
0 - malloc
0 - free
1 - write
1 - close
1 - fork
1 - waitpid
0 - signal
0 - kill
1 - exit
1 - chdir
1 - execve
1 - dup
1 - dup2
1 - pipe
1 - strcmp
0 - strncmp
*/
