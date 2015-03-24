/*
 * 练习题 2.59
 *
 * 编写一个 C 表达式，使它生成一个字，由 x 的最低有效字节和 y 中剩下的字节组成。
 * 对于运算数 x=0x89ABCDEF 和 y=0x76543210，就得到 0x765432EF。
 */
int combine_word(unsigned x, unsigned y)
{
        return (x & 0xFF) | (y & ~0xFF);
}
