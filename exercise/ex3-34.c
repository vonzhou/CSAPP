/*
 * 练习题 3.34
 */

int rfun(unsigned x)
{
        if (!x)
                return 0;
        unsigned nx = x >> 1;
        int rv = rfun(nx);
        return rv + (x & 1);
}

#include <stdio.h>

int main(void)
{
        int x = 0x73;
        int n = rfun(x);

        printf("0x%X: %d\n", x, n);

        return 0;
}
