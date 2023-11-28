

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char *E1 = "error: cd: bad arguments";
char *E2 = "error: cd: cannot change directory to ";
char *E3 = "error: fatal";
char *E4 = "error: cannot execute ";

size_t len(char *s) {
    size_t i = 0;
    while (s[i]) i++;
    return i;
}

int main(int ac, char **av, char **envp) {
    int fd[2];
    int i = 1;
    int fdt;

    fdt = dup(0);
    while (i <ac && av[i]) {
        char **C = &av[i];
        if (strcmp(C[0], "|") == 0 || strcmp(C[0], ";") == 0) {
            i++;
            continue;
        }
        while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0) i++;

        if (strcmp(C[0], "cd") == 0) {
            if (*(av + i - 2) != C[0]) {
                write(2, E1, len(E1));
                write(2, "\n", 1);
            } else if (chdir(C[1]) != 0) {
                write(2, E2, len(E2));
                write(2, C[1], len(C[1]));
                write(2, "\n", 1);
            }
        } else if (av[i] && strcmp(av[i], "|") == 0) {
            pipe(fd);
            if (fork()) {
                close(fdt);
                close(fd[1]);
                fdt = fd[0];
            } else {
                dup2(fdt, 0);
                close(fdt);
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);
                av[i] = NULL;

                execve(C[0], C, envp);
                write(2, E4, len(E4));
                write(2, C[0], len(C[0]));
                write(2, "\n", 1);
            }
        } else if (!av[i] || strcmp(av[i], ";") == 0) {
            if (fork()) {
                close(fdt);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                fdt = dup(0);
            } else {
                dup2(fdt, 0);
                close(fdt);
                av[i] = NULL;

                execve(C[0], C, envp);
                write(2, E4, len(E4));
                write(2, C[0], len(C[0]));
                write(2, "\n", 1);
            }
        }
        i++;
    }
    close(fdt);
    return 0;
}
