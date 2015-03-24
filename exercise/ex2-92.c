/*
 * 家庭作业 2.92
 * mofaph@gmail.com
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute -f.  If f is Nan, then return f.
 * float_bits float_absval(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 -f。如果 f 是 NaN，你的函数应该简单地返回 f。测试你
 * 的函数，对参数 f 可以取的所有 2^32 个值求值，将结果与你使用机器的浮点运算得到
 * 的结果相比较。
 */

typedef unsigned float_bits;

/* Compute -f.  If f is NaN, then return f */
float_bits float_negate(float_bits f)
{
        unsigned sign = f >> 31;
        unsigned exp = f >> 23 & 0xFF;
        unsigned frac = f & 0x7FFFFF;

        if (exp == 0xFF && frac != 0) /* NaN */
                return f;
        return (~sign << 31) | (exp << 23) | frac;
}
