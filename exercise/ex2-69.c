/*
 * 练习题 2.69
 *
 * Do rotating right shift.  Assume 0 <= n < w
 * Example when x = 0x12345678 and w=32:
 *     n=4 -> 0x81234567, n=20 -> 0x45678123
 *
 * 函数应该遵循位级整数编码规则。要注意 n = 0 的情况。
 */
unsigned rotate_right(unsigned x, int n)
{
        int w = sizeof(int) << 3;
        /* 这里左移一位，解决 n = 0 的情况 */
        return ((x << (w-n-1)) << 1) + (x >> n);
}
