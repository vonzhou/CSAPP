/*
 * 练习题 8.7 编写一个叫做 snooze 的程序
 *
 * 有一个命令行参数，用这个参数调用练习题中的 snooze 函数，然后终止。
 * 编写程序，使得用户可以通过在键盘上输入 ctrl-c 中断 snooze 函数。
 *
 * unix> cc ex8-7.c
 * unix> ./a.out 5
 * Slept for 3 of 5 secs.       User hits ctrl-c after 3 seconds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
        return;
}

unsigned int snooze(unsigned int secs)
{
        unsigned sleep_secs, reserve_secs;

        reserve_secs = sleep(secs);
        sleep_secs = secs - reserve_secs;

        printf("Slept for %u of %u secs\t\t"
               "User hits ctrl-c after %u seconds\n",
               sleep_secs, secs, sleep_secs);

        return reserve_secs;
}

int main(int argc, char *argv[])
{
        unsigned secs;

        if (argc != 2) {
                fprintf(stderr, "usage: %s seconds\n", argv[0]);
                exit(1);
        }

        if (signal(SIGINT, handler) == SIG_ERR) {
                fprintf(stderr, "signal error: %s\n", strerror(errno));
                exit(0);
        }

        secs = atoi(argv[1]);
        snooze((unsigned)secs);

        return 0;
}
