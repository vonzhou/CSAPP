/*
 * 8.22
 *
 * mofaph@gmail.com
 *
 * 编写 UNIX system 函数的你自己的版本
 *
 *     int mysystem(char *command);
 *
 * mysystem 函数通过调用“/bin/sh -c command”来执行 command，然后在 command 完成
 * 后返回。如果 command（通过调用 exit 函数或者执行一条 return 语句）正常退出，那
 * 么 mysystem 返回 command 退出状态。例如，如果 command 通过调用 exit(8) 终止，
 * 那么 mysystem 返回值 8。否则，如果 command 是异常终止的，那么 mysystem 就返回
 * 外壳返回的状态。
 *
 * unix> cc ex8-22.c t8-22.c
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char *environ[];

int mysystem(char *command)
{
        pid_t pid;

        pid = fork();

        /* error */
        if (pid < 0) {
                perror("fork");
                return -1;
        }

        /* child */
        else if (pid == 0) {
                const int MAX_OPTION = 4096;
                char *argv[MAX_OPTION];

                if (!command) {
                        fprintf(stderr, "mysystem: command is NULL\n");
                        exit(-1);
                }

                /*
                 * BUG: The code below can't handler command which is
                 * emacs/nano/top.
                 *
                 * The error message is something like: TERM not set.
                 */
                char *term = getenv("TERM");
                if (!term) {
                        int err = setenv("TERM", "xterm", 0);
                        if (err)
                                fprintf(stderr, "TERM not set\n");
                }

                argv[0] = "sh";
                argv[1] = "-c";
                argv[2] = command;
                argv[3] = NULL;
                execve("/bin/sh", argv, environ);

                /* Something went wrong */
                perror("execve");
                return -1;
        }

        /* parent */
        else {
                int status, ret;

                ret = waitpid(pid, &status, 0);

                /* waitpid error */
                if (ret < 0) {
                        perror("waitpid");
                        return -1;
                }

                /* The child process is terminated */
                if (WIFEXITED(status)) {
                        int child_ret = WEXITSTATUS(status);
                        return child_ret;
                }

                /* Ignore other situation.  Good but not great? */
                return 0;
        }
}
