/*
 * 测试家庭作业 2.96
 *
 * 编译：
 *     $ cc ex2-89.c ex2-96.c t2-96.c
 *
 * 测试：
 *     $ ./a.out
 *
 * mofaph@gmail.com
 */

#include <limits.h>
#include <stdio.h>

typedef unsigned float_bits;

extern float u2f(unsigned u);
extern int float_f2i(float_bits f); /* (int)f */

int main(void)
{
        float f;
        unsigned u, t;

        int i = INT_MIN;
        do {
                u = float_f2i(i);
                f = u2f(i);
                t = (int)f;
                if (u != t)
                        printf("0x%08X: [GOOD: 0x%08X] [BAD: 0x%08X]\n", i, t, u);
        } while (i++ != INT_MAX);

        return 0;
}
