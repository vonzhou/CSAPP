/*
 * 2.59
 *
 * mofaph@gmail.com
 * 2013-12-17
 *
 * unix> cc -Wall ex2-59.c t2-59.c -o ex2-59
 */

#include <stdio.h>

extern int combine_word(unsigned x, unsigned y);

int main(void)
{
        int x = 0x89ABCDEF;
        int y = 0x76543210;
        int z = combine_word(x, y);

        printf("x=0x%X, y=0x%X, combine_word=0x%X\n", x, y, z);

        return 0;
}
