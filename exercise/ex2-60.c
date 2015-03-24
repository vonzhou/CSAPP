/*
 * 练习题 2.60
 *
 * 假设我们将一个 w 位的字中的字节从 0（最低位）到 w/8-1（最高位）编号。写出下面
 * C 函数的代码，它会返回一个无符号值，其中参数 x 的字节 i 被替换成字节 b：
 *
 * unsigned replace_byte(unsigned x, unsigned char b, int i);
 *
 * 以下的一些示例，说明了这个函数该如何工作：
 *
 * replace_byte(0x12345678, 0xAB, 2) --> 0x12AB5678
 * replace_byte(0x12345678, 0xAB, 0) --> 0x123456AB
 */

unsigned replace_byte(unsigned x, unsigned char b, int i)
{
        /* 1. 首先将 0x12345678 变为 0x12005678 */
        int w = sizeof(int) - 1; /* 取值范围: 0~3 */
        int shift_left = (i & w)<<3;
        unsigned m = x & ~(0xFF << shift_left);

        /* 2. 将 0xAB 左移 2 两个字节得到数值 0x00AB0000 */
        unsigned int n = (unsigned)b << shift_left;

        /* 3. 将 0x12005678+0x00AB0000 作为结果返回 */
        return m + n;
}
