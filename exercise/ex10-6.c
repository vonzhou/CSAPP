/*
 * 10.6
 *
 * mofaph@gmail.com
 * 2013/5/11
 *
 * 下面程序的输出是什么？
 *
 * $ touch {foo,bar,baz}.txt
 * $ cc -I../common ../common/csapp.c ex10-6.c -lpthread
 */

#include "csapp.h"

int main(void)
{
        int fd1, fd2;

        fd1 = Open("foo.txt", O_RDONLY, 0); /* fd1: 3 */
        fd2 = Open("bar.txt", O_RDONLY, 0); /* fd2: 4 */
        Close(fd2);
        fd2 = Open("baz.txt", O_RDONLY, 0); /* fd2: 4 */
        printf("fd2 = %d\n", fd2);
        exit(0);
}
