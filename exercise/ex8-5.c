/*
 * 8.5
 *
 * 编写一个 sleep 的包装函数，叫做 snooze，带有下面的接口
 *
 * unsigned int snooze(unsigned int secs);
 *
 * 除了 snooze 函数会打印出一条信息来描述进程实际休眠了多长时间外，它和 sleep 函
 * 数的行为完全一样：
 *
 * Slept for 4 of 5 secs.
 */

#include <stdio.h>

#include <unistd.h>

unsigned int snooze(unsigned int secs)
{
        unsigned sleep_secs;

        sleep_secs = sleep(secs);

        printf("Slept for %u of %u secs\n", secs - sleep_secs, secs);
        return sleep_secs;
}

int main(void)
{
        snooze(3);
        return 0;
}
