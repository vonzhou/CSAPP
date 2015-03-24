/*
 * 家庭作业 2.91
 * mofaph@gmail.com
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute |f|.  If f is NaN, then return f.
 * float_bits float_absval(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 |f|。如果 f 是 NaN，你的函数应该简单地返回 f。测
 * 试你的函数，对参数 f 可以取的所有 2^32 个值求值，将结果与你实用机器的浮点运
 * 算得到的结果相比较。
 */

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
        unsigned exp = f >> 23 & 0xFF;
        unsigned frac = f & 0x7FFFFF;

        /* NaN */
        if (exp == 0xFF && frac != 0)
                return f;

        return (exp << 23) | frac; /* sign=0 */
}

/*
 * How to build:
 *     $ cc ex2-89.c ex2-91.c
 */

#include <stdio.h>

extern float u2f(unsigned x);   /* ex2-89.c */

unsigned f2u(float f)
{
        union { float f; unsigned u; } a;
        a.f = f;
        return a.u;
}

/* test driver */
int main(void)
{
        float f = -0.0;
        unsigned uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        f = 0.0;
        uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        f = 1.0;
        uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        f = -1.0;
        uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        f = u2f(0x7F800000);    /* +oo */
        uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        f = u2f(0xFF800000);    /* -oo */
        uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        f = u2f(0x7F800001);    /* NaN */
        uf = f2u(f);
        printf("%f(0x%X): %f\n", f, uf, u2f(float_absval(uf)));

        return 0;
}
