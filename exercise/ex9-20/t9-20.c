/*
 * 9.20 -- test driver
 *
 * mofaph@gmail.com
 * 2013-6-28
 *
 * unix> cc -Wall ex9-20.c t9-20.c -o ex9-20
 * unix> ./ex9-20
 */

#include <stdio.h>

extern int mo_init(void);
extern void mo_free(void *bp);
extern void *mo_malloc(size_t size);

#ifndef MAX_ITEM
#  define MAX_ITEM (1<<17)
#endif

int main(void)
{
        if (mo_init() < 0)
                return -1;

        int i;
        char *buf[MAX_ITEM];
        for (i = 1; i < MAX_ITEM; i++) {
                buf[i] = mo_malloc(i);
        }
        for (i = 1; i < MAX_ITEM; i++) {
                mo_free(buf[i]);
        }

        return 0;
}
