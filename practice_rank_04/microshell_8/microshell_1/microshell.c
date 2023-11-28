
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

size_t len(char *s) {
    size_t i = 0;
    while (s[i]) i++;
    return i;
}

void print_error(char *a, char *b) {
    if (a) write(STDERR_FILENO, a, len(a));
    if (b) write(STDERR_FILENO, b, len(b));
    write(STDERR_FILENO, "\n", 1);
}

int main(int argc, char **argv, char **envp) {
    int i = 1;
    int fd[2];
    int fdt = dup(0);

    while (i < argc && argv[i]) {
        char **cmd = &argv[i];
        if (!strcmp(cmd[0], ";") || !strcmp(cmd[0], "|")) {
            i++;
            continue;
        }
        while (argv[i] && strcmp(argv[i], ";") != 0 && strcmp(argv[i], "|") != 0) {
            i++;
        }
        if (strcmp(cmd[0], "cd") == 0) {
            // printf("cd\n");         // Debug
            if ((cmd) != (argv + i - 2)) {
                print_error("error: cd: bad arguments", NULL);
            } else if (chdir(cmd[1]) != 0) {
                print_error("error: cd: cannot change directory to ", cmd[1]);
            }
        } else if (!argv[i] || strcmp(argv[i], ";") == 0) {
            // printf(";\n");         // Debug

            if (fork()) {
                close(fdt);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                fdt = dup(0);
            } else {
                dup2(fdt, 0);
                close(fdt);
                argv[i] = NULL;

                execve(cmd[0], cmd, envp);
                print_error("error: cannot execute ", cmd[0]);
            }
        } else if (strcmp(argv[i], "|") == 0) {
            // printf("|\n");         // Debug

            pipe(fd);
            if (fork()) {
                close(fdt);
                close(fd[1]);
                fdt = fd[0];
            } else {
                dup2(fdt, 0);
                close(fdt);
                dup2(fd[1], 1);
                close(fd[1]);
                close(fd[0]);
                argv[i] = NULL;

                execve(cmd[0], cmd, envp);
                print_error("error: cannot execute ", cmd[0]);
            }
        }
        i++;
    }
    close(fdt);
    return (0);
}
