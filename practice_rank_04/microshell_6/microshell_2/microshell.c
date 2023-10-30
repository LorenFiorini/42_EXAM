
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

size_t len(char *a) {
    size_t i = 0;
    while (a[i])
        i++;
    return (i);
}

void std_err(char *a, char *b) {
    if (a)
        write(STDERR_FILENO, a, len(a));
    if (b)
        write(STDERR_FILENO, b, len(b));
    write(STDERR_FILENO, "\n", 1);
}

int main(int argc, char **argv, char **envp) {
    (void) argc;
    int fd[3];
    int i = 1;

    fd[2] = dup(0);
    while (i < argc && argv[i]) {
        char **cmd = &argv[i];
        while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0) {
            i++;
        }
        if ((cmd) == (argv + i)) {
            i++;
            continue;
        }
        if (strcmp(cmd[0], "cd") == 0) {
            if (cmd[0] != argv[i - 2]) {
                std_err("error: cd: bad arguments", NULL);
            } else if (chdir(argv[i - 1]) != 0) {
                std_err("error: cd: cannot change directory to ", argv[i - 1]);
            }
        } else if (argv[i] && strcmp(argv[i], "|") == 0) {
            if (pipe(fd)) {
                std_err("error: fatal", NULL);
            }
            int tmp = fd[0];
            fd[0] = fd[2];
            fd[2] = tmp;

            int pid = fork();
            if (pid < 0) {
                std_err("error: fatal", NULL);
                exit(1);
            } else if (pid == 0) {
                argv[i] = NULL;
                dup2(fd[0], 0);
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);
                close(fd[2]);

                execve(cmd[0], cmd, envp);
                std_err("error: cannot execute ", cmd[0]);
            } else {
                close(fd[0]);
                close(fd[1]);
            
            }
        } else if (!argv[i] || strcmp(argv[i], ";") == 0) {
            int pid = fork();
            if (pid < 0) {
                std_err("error: fatal", NULL);
                exit(1);
            } else if (pid == 0) {
                dup2(fd[2], 0);
                close(fd[2]);
                argv[i] = NULL;

                execve(cmd[0], cmd, envp);
                std_err("error: cannot execute ", cmd[0]);
            } else {
                close(fd[2]);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                fd[2] = dup(0);
            }
        }
        i++;
    }
    close(fd[2]);
    return (0);
}
