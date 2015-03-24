/*
 * 写出代码实现如下函数：
 *
 * Return 1 when any even bit of x equals 1; 0 otherwise.  Assume w=32
 *
 *         int any_even_one(unsigned x);
 *
 * 函数应该遵循位级整数编码规则，不过你可以假设数据类型 int 有 w=32 位。
 */

int any_even_one(unsigned x)
{
        return (x & 0x5555) & 1;
}
