/*
 * 8.12
 *
 * 这个程序会输出多少个“hello”输出行？
 *
 * unix> gcc -I../common ex8-12.c ../common/csapp.c -lpthread
 * #8
 */

#include "csapp.h"

void doit()
{
        Fork();
        Fork();
        printf("hello\n");
        return;
}

int main()
{
        doit();
        printf("hello\n");
        return;
}
