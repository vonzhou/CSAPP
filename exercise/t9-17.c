/*
 * test 9.17
 *
 * mofaph@gmail.com
 *
 * unix> gcc -I../common ex9-17.c t9-17.c ../sample/ch09/memlib.c ../common/csapp.c -lpthread
 */

#include <stdio.h>

extern void mem_init(void);
extern int mm_init(void);
extern void mm_free(void *bp);
extern void *mm_malloc(size_t size);

int main(void)
{
        mem_init();
        if (mm_init() < 0)
                return -1;

        char *buf  = mm_malloc(1);
        printf("buf : %p\n", buf);
        if (buf)
                mm_free(buf);

        char *buf2 = mm_malloc(4);
        printf("buf2: %p\n", buf2);
        if (buf2)
                mm_free(buf2);

        char *buf3 = mm_malloc(8);
        printf("buf3: %p\n", buf3);

        char *buf4 = mm_malloc(12);
        printf("buf4: %p\n", buf4);

        if (buf3)
                mm_free(buf3);
        if (buf4)
                mm_free(buf4);

        buf  = mm_malloc(4);
        printf("buf : %p\n", buf);

        buf2 = mm_malloc(9);
        printf("buf2: %p\n", buf2);

        if (buf)
                mm_free(buf);
        if (buf2)
                mm_free(buf2);

        return 0;
}
