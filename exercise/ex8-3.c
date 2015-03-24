/*
 * 8.3 -- code/ecf/waitprob0.c
 *
 * 列出下面程序所有可能的输出序列
 *
 * $ gcc -iquote../common ../common/csapp.c ex8-3.c -lpthread
 */

#include <stdio.h>
#include <stdlib.h>

#include "csapp.h"

int main(void)
{
        if (Fork() == 0) {      /* child */
                printf("a");
        } else {                /* parent */
                printf("b");
                waitpid(-1, NULL, 0);
        }

        printf("c");
        exit(0);
}
