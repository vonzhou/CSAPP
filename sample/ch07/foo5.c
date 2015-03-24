/*
 * foo5.c -- p456
 */

#include <stdio.h>

void f(void);

/*
 * 在一台 IA32/Linux 机器上，double 类型是 8 个字节，而 int 类型是 4 个字节。因此，
 * bar5.c 的第 6 行中的赋值 x=-0.0 将用负零的双精度浮点表示覆盖存储器中 x 和 y 的位置！
 *
 * 当我们怀疑有此类错误的时候，使用像 GCC 的 -fno-common 这样的选项调用链接器，这
 * 个选项会告诉链接器，在遇到多重定义的全局符号时，输出一条警告信息
 */

int x = 15213;
int y = 15212;

int main()
{
        f();
        printf("x = 0x%x, y = 0x%x\n", x, y);
        return 0;
}
