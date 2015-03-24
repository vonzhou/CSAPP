/*
 * 用于测试 ex2-95.c 的代码
 *
 * 编译：
 *     $ cc ex2-89.c ex2-95.c t2-95.c
 *
 * 测试方法：
 *     $ ./a.out
 *     $ time ./a.out > t2-95.test
 *
 * mofaph@gmail.com
 */

#include <stdio.h>              /* printf() */
#include <limits.h>             /* INT_MIN INT_MAX */

typedef unsigned float_bits;

extern unsigned f2u(float f);       /* ex2-89.c */
extern float_bits float_i2f(int i); /* ex2-95.c */

int main(void)
{
        float f;
        unsigned u, t;

        int i = INT_MIN;
        do {
                f = (float) i;
                u = f2u(f);
                t = float_i2f(i);
                if (u != t)
                        printf("BAD: 0x%X, 0x%X, 0x%X\n", t, i, u);
        } while (i++ != INT_MAX);

        return 0;
}
