/*
 * 家庭作业 2.77
 *
 * 写出具有如下原型的函数的代码：
 *
 * // Divide by power of two.  Assume 0 <= k < w-1
 * int divide_power2(int x, int k);
 *
 * 该函数要用正确的舍入计算 x/2^k，并且应该遵循位级整数编码规则。
 */

#include <limits.h>             /* INT_MIN */

/*
 * 对于整数除法，结果应该是向零舍入。而对于右移运算，结果是向下舍入。
 *
 * 对于 x >= 0 的情况，简单的右移运算的结果也是整数除法的结果。而对于 x < 0 的情
 * 况，因为结果是向下舍入的，而我们需要的是向上舍入的结果。这样子，当 x < 0 时，
 * 我们为 x 加上一个偏置值 (1<<k)-1 就可以使右移的结果向上舍入了。
 */
int divide_power2(int x, int k)
{
        int sign = (x & INT_MIN) == INT_MIN;
        int mask = (1 << k) - 1;
        int bias = (mask + !sign) & mask;
        return (x + bias) >> k;
}
