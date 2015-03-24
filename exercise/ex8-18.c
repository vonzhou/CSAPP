/*
 * 8.18
 *
 * mofaph@gmail.com
 *
 * unix> cc -I../common ex8-18.c ../common/csapp.c -lpthread
 *
 * 判断下面哪个输出是可能的。注意：atexit 函数以一个指向函数的指针为输入，并将它
 * 添加到函数列表中（初始为空），当 exit 函数被调用时，会调用该列表中的函数。
 *
 * A. 112002
 * B. 211020
 * C. 102120
 * D. 122001
 * E. 100212
 *
 * 可能的序列： A C E
 */

#include "csapp.h"

void end(void)
{
        printf("2");
}

int main()
{
        if (Fork() == 0)
                atexit(end);
        if (Fork() == 0)
                printf("0");
        else
                printf("1");
        exit(0);
}
