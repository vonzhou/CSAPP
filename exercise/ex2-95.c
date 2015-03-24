/*
 * 家庭作业 2.95
 * mofaph@gmail.com
 *
 * 遵循位级浮点编码规则，实现具有如下原型的函数：
 *
 * // Compute (float) i
 * float_bits float_i2f(int i);
 *
 * 对于参数 i，这个函数计算 (float)i 的位级表示。
 * 测试你的函数，对参数 f 可以取的所有 2^32 个值求值，将结果与你使用机器的浮点
 * 运算得到的结果相比较。
 */

#include <limits.h>

typedef unsigned float_bits;

/*
 * 假设整数的位宽和单精度浮点数的位宽是相同的
 *
 * 当一个整数需要至少 24 位表示，则表明这个整数转换成浮点数时需要舍入。由于一个整
 * 数转换将会转换成规格化的浮点数，因此最左边的 1 将会成为隐藏的小数部分。（0 是
 * 唯一的非规格化数）
 *
 * 当转换的数字是负数时，由于补码表示的原因，因此我们需要把它转换成正数表示的数字
 * 形式。同时，我们需要记录负数的符号位。
 *
 * 当出现需要舍入的时候，将会出现 3 种情况：
 *
 *     1. 截断的部分大于截断的一半，向上舍入
 *     2. 截断的部分等于截断的一半，向偶数舍入
 *     3. 截断的部分小于截断的一半，向下舍入
 */

float_bits float_i2f(int i)
{
        unsigned sign, exp, frac;
        unsigned leftmost, rightmost, t;

        if (i == 0)
                return i;

        sign = (i & INT_MIN) == INT_MIN;
        if (sign)
                i = ~i + 1;
        for (rightmost = 1, t = INT_MIN; (t & i) != t; t >>= 1)
                rightmost++;
        leftmost = (sizeof(int) << 3) - rightmost;
        exp = leftmost + 127;

        int shift;
        if (leftmost > 23) {
                shift = leftmost - 23;
                int mask = ((1 << shift) - 1) & i;
                int half = 1 << (shift - 1);
                int hide = 1 << shift;
                int round = mask>half || (mask==half && (i&hide)==hide);
                frac = (i >> shift) & 0x7FFFFF;
                if (frac == 0x7FFFFF && round == 1)
                        frac = 0, exp++;
                else
                        frac += round;
        } else {
                shift = 23 - leftmost;
                frac = (i << shift) & 0x7FFFFF;
        }

        return (sign << 31) | (exp << 23) | frac;
}
