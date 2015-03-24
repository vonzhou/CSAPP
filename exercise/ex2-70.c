/*
 * 练习题 2.70
 *
 * 写出具有如下原型的函数的代码：
 *
 * Return 1 when x can be represented as an n-bit, 2's complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 *
 *         int fits_bits(int x, int n);
 *
 * 函数应该遵循位级整数编码规则。
 */

/*
 * 如果我们需要观察一个数是否可以使用 n 位补码和表示。我们可以将这个数的低 n-1 位
 * 全部置零，然后观察 w...n 这些位。
 *
 * 对于正数来说，如果这些 w...n 这些位非零的话，则说明 n 位补码不足以表示这个数。
 * 对于负数来说，如果这些 w...n 这些位不是全 1 的话，则说明 n 位补码不足以表示这
 * 个数。
 */
int fits_bits(int x, int n)
{
        /* 1. 构造位 w...n 全 1，位 n-1...0 全 0 的位向量 */
        int s = ~((1 << (n - 1)) - 1);

        /* 2. 将 x 的低 n-1 位置零，其他位保留 */
        x &= s;

        /* 3. 此时，w...n 位是全 0 或者全 1，才可以用 n 位补码表示这个数 */
        return !x || x == s;
}
