/*
 * 8.14
 *
 * 下面这个程序会输出多少个“hello”输出行？
 *
 * unix> gcc -I../common ex8-14.c ../common/csapp.c -lpthread
 *
 * 第一个 Fork() 成功，第二个 Fork() 失败： 1
 * 第一个 Fork() 成功，第二个 Fork() 成功： 3
 * 第一个 Fork() 失败： 0
 */

#include "csapp.h"

void doit()
{
        if (Fork() == 0) {
                Fork();
                printf("hello\n");
                exit(0);
        }
        return;
}

int main()
{
        doit();
        printf("hello\n");
        exit(0);
}
