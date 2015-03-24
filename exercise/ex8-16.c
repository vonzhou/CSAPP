/*
 * 8.16
 *
 * unix> gcc -I../common ex8-16.c ../common/csapp.c -lpthread
 * counter = 2
 */

#include "csapp.h"

int counter = 1;

int main()
{
        if (fork() == 0) {
                counter--;
                exit(0);
        } else {
                Wait(NULL);
                printf("counter = %d\n", ++counter);
        }

        exit(0);
}
