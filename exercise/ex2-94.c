/*
 * 家庭作业 2.94
 * mofaph@gmail.com
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute 2*f.  If f is NaN, then return f.
 * float_bits float_twice(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 2.0*f。如果 f 是 NaN，你的函数应该简单地返回 f。
 * 测试你的函数，对参数 f 可以取的所有 2^32 个值求值，将结果与你使用机器的浮点
 * 运算得到的结果相比较。
 */

typedef unsigned float_bits;

/* Compute 2*f.  If f is NaN, then return f. */
float_bits float_twice(float_bits f)
{
        unsigned sign = f >> 31;
        unsigned exp = (f >> 23) & 0xFF;
        unsigned frac = f & 0x7FFFFF;

        /* NaN, +oo, -oo */
        if (exp == 0xFF)
                return f;

        if (exp == 0xFE) {
                exp = 0xFF;
                frac = 0;
        } else if (exp > 0) {
                exp++;
        } else /* exp == 0 */ {
                if ((frac & 0x400000) == 0x400000) {
                        exp = 1;
                        frac = (frac << 1) & 0x7FFFFF;
                } else {
                        frac <<= 1;
                }
        }

        return (sign << 31) | (exp << 23) | frac;
}
