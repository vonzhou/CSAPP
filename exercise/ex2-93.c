/*
 * 家庭作业 2.93
 * mofaph@gmail.com
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute 0.5*f.  If f is NaN, then return f.
 * float_bits float_half(float_bits f);
 *
 * 对于浮点数 f，这个函数计算 0.5*f。如果 f 是 NaN，你的函数应该简单返回 f。测
 * 试你的函数，对参数 f 可以取的所有 2^32 个值求值，将结果与你使用机器的浮点运
 * 算得到的结果相比较。
 */

typedef unsigned float_bits;

/* Compute 0.5*f.  If f is NaN, then return f. */
float_bits float_half(float_bits f)
{
        unsigned sign = f >> 31;
        unsigned exp = f >> 23 & 0xFF;
        unsigned frac = f & 0x7FFFFF;

        /* NaN, +oo, -oo */
        if (exp == 0xFF)
                return f;

        /* 按照向偶数舍入的方式，只有最低 2 位为全 1 时，才需要舍入 */
        unsigned round = (frac & 3) == 3;

        /*
         * 我们需要特别注意当 exp=1 的情况。因为这时阶码域的数值是可表示的最小范
         * 围，exp 的最终取值不能单纯地减去 1，而应该对小数域进行操作。此时，小数
         * 域有一个隐藏的小数点右边的 1。
         *
         * frac==0x7FFFFF(小数域全 1)，这时小数点的右边一位应该是 1，此时小数域
         * 余下的部分应该是全 1，加上舍入的 1，此时 M=1.0。因此，exp=1,frac=0。
         *
         * frac!=0x7FFFFF，这时只需要处理舍入的情况。
         */
        if (exp > 1) {
                exp--;
        } else if (exp == 1) {
                if (frac == 0x7FFFFF) {
                        frac = 0; /* 舍入后 M = 1.0 */
                } else /* frac != 0x7FFFFF */ {
                        exp = 0;
                        frac = (1 << 22) + (frac >> 1) + round;
                }
        } else /* exp == 0 */ {
                frac = (frac >> 1) + round;
        }

        return (sign << 31) | (exp << 23) | frac;
}
