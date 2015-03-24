/*
 * 练习题 2.68
 *
 * 写出具有如下原型的函数的代码
 *
 * Make with least signficant n bits set to 1
 * Example: n = 6 --> 0x3f, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 *
 *         int lower_bits(int x, int n);
 *
 * 函数应该遵循位级整数编码规则。要注意 n = w 的情况
 */

int lower_bits(int x, int n)
{
        int r = 0;
        int s = n - 1;

        /* 1. 构造一个最低 n 位为 1 的数 */
        r = (1<<s) - 1 + (1<<s);

        /* 2. 将这个数与原来的数字进行或运算作为结果返回 */
        return x | r;
}
