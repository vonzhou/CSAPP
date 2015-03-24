/*
 * 家庭作业 2.96
 * mofaph@gmail.com
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute (int) f.
 * // If conversion causes overflow or f is NaN, return 0x80000000
 * int float_f2i(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 (int)f。你的函数应该向零舍入。如果f 不能用整数表示
 * （例如，超出表示范围，或者它是一个 NaN），那么函数应该返回0x80000000。测试你的
 * 函数，对参数 f 可以取的所有 2^32 个值求值，将结果与你使用机器的浮点运算得到的
 * 结果相比较。
 */

#include <limits.h>             /* INT_MIN */

typedef unsigned float_bits;

/*
 * 从 float 或者 double 转换成 int，值将会向零舍入。例如，1.999 将被转换成 1，而
 * -1.999 将被转换成 -1。
 *
 * 进一步来说，值可能会溢出。C 语言标准没有对这种情况指定固定的结果。
 *
 * 与 Intel 兼容的微处理器指定位模式 [10...00]（字长位 w 时的 INT_MIN）为整数不确
 * 定（integer indefinite）值。一个从浮点数到整数的转换，如果不能为该浮点数找到一
 * 个合理的整数近似值，就会产生这样一个值。因此，表达式 (int)+1e10 会得到
 * -21483648，即从一个正值变成了一个负值。
 *
 * 注意：单精度浮点数精确只能表示 0~33,554,432 的整数。
 */

int float_f2i(float_bits f)
{
        unsigned sign = f >> 31;
        unsigned exp = (f >> 23) & 0xFF;
        unsigned frac = f & 0x7FFFFF;
        int E = (int)exp - 127;

        if (exp == 0xFF)        /* NaN, +oo, -oo */
                return INT_MIN;
        if (exp == 0 || E < 0)
                return 0;
        if (sign == 0 && E > 30)
                return INT_MIN;
        if (sign == 1 && E > 31)
                return INT_MIN;
        if (sign == 1 && E == 31 && frac > 0)
                return INT_MIN;

        int shift;
        if (E > 23) {
                shift = E - 23;
                frac = (1 << E) + (frac << shift);
        } else /* 0 <= E <= 23 */ {
                shift = 23 - E;
                frac = (1 << E) + (frac >> shift);
        }

        if (sign == 1)
                frac = ~frac + 1;

        return frac;
}
