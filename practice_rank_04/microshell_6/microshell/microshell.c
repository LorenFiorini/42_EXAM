

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


size_t len(char *s) {
    size_t i = 0;
    while (s[i]) {
        i++;
    }
    return i;
}

void err(char *a, char *b) {
    write(2, a, len(a));
    if (b)
        write(2, b, len(b));
    write(2, "\n", 1);
}


int main(int argc, char **argv, char **envp)
{
    int fd[3];
    int i = 1;

    fd[2] = dup(0);
    while (i < argc && argv[i]) {
        char **cmd = &argv[i];
        while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0) {
            printf("%s\n", argv[i]);
            i++;
        }
        if (cmd == (argv + i)) {
            i++;
            continue ;
        }
        if (strcmp(cmd[0], "cd") == 0) {
            printf("-> cd \n");
            if (cmd != (argv + i - 2)) {
                err("error: cd: bad arguments", NULL);
            } else if (chdir(cmd[1]) != 0) {
                err("error: cd: cannot change directory to ", cmd[1]);
            }
        } else if (strcmp(argv[i], "|") == 0) {
            printf("-> | \n");

            pipe(fd);
            if (fork()) {
                printf(" Parent \n");

                close(fd[1]);
                close(fd[2]);
                fd[2] = fd[0];
            } else {
                printf(" Child \n");

                argv[i] = NULL;
                close(fd[0]);
                dup2(0, fd[2]);
                close(fd[2]);
                dup2(1, fd[1]);
                close(fd[1]);

                execve(cmd[0], cmd, envp);
                err("error: cannot execute ", cmd + 1);
            }
        } else if (!argv[i] || strcmp(argv[i], ";") == 0) {
            printf("-> ; \n");

            if (fork()) {
                printf(" Parent \n");

                close(fd[2]);
                while (waitpid(-1, NULL, WUNTRACED) != -1);
                    ;
                fd[2] = dup(0);
            } else {
                printf(" Child \n");

                argv[i] = NULL;
                dup2(0, fd[2]);
                close(fd[2]);

                execve(cmd[0], cmd, envp);
                err("error: cannot execute ", cmd[1]);
            }
        } 
        i++;

    }
    close(fd[2]);
    return (0);
}
