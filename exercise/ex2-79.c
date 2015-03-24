/*
 * 家庭作业 2.79
 *
 * 写出函数 fiveeighths 的代码，对于整数参数 x，计算 5/8x 的值，向零舍入。它不会
 * 溢出。函数应该遵循整数位级编码规则。
 */

#include <limits.h>

/*
 * 对于计算 5/8x 的值，可以理解为两种情况：
 *
 *     1. 5/(8*x)
 *     2. (5/8)*x
 *
 * 对于第一种情况，x != 0 时，所得的结果是 0。x == 0 时，结果是没有定义的。对于这
 * 种求值，没有意义。因此，下面我们将题目理解为求值 (5/8)*x。
 *
 * 基本的思路是，5*x/8 = x/2 + x/8 + f
 *
 * f 的取值是 x/2 和 x/8 的小数部分之和 >=1 时，f=1。对于负数的情况，小数点之和
 * <= -1，则 f = -1。否则，f=0。
 *
 * 对于正数的情况，求两个整数的小数点之和就是截断两个数的最低三位，然后右移 3 位。
 *
 * 考虑负数的情况，我们可以发现，最低三位的数值+(-8)就是余数的数值（此时余数小于
 * 0）。对两个整数都这样处理，我们就可以得到两个负数的余数之和。然后加上偏执值右
 * 移 3 位，得到的就是小数点之和。只有当符号位和最低三位数值都是 1 时，才会有
 * f=-1。
 */
int fiveeighths(int x)
{
        int sign         = (x & INT_MIN) == INT_MIN;
        int lowest_one   = x & 1;
        int lowest_three = !!(x & 7);

        /*
         * 只有 sign=1 && (lowest_one||lowest_three) 求值为 1 时，mask=mask2=-8
         * 否则，mask=mask2=0
         */
        int mask  = ~(((sign & lowest_one)   << 3) - 1) & -8;
        int mask2 = ~(((sign & lowest_three) << 3) - 1) & -8;

        int fraction  = ((x & 1) << 2) + mask;
        int fraction2 = (x & 7) + mask2;

        int bias  = (1 + !sign) & 1;
        int bias2 = (7 + !sign) & 7;
        int remainder = (fraction + fraction2 + bias2) >> 3;

        return ((x + bias) >> 1) + ((x + bias2) >> 3) + remainder;
}
