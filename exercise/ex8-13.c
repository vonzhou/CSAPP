/*
 * 8.13
 *
 * 下面程序的一种可能的输出是什么？
 *
 * unix> gcc -I../common ex8-13.c ../common/csapp.c -lpthread
 *
 * 父进程先运行：
 * 4
 * 3
 * 2
 *
 * 子进程先运行：
 * 2
 * 4
 * 3
 *
 * 创建进程失败：
 * 4
 * 3
 */

#include "csapp.h"

int main()
{
        int x = 3;

        if (Fork() != 0)
                printf("x=%d\n", ++x);

        printf("x=%d\n", --x);
        exit(0);
}
