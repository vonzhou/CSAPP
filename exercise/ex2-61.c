/*
 * 练习题 2.61
 *
 * 写一个 C 表达式，在下列描述的条件下产生 1，而在其他情况下得到 0。假设 x 是
 * int 类型。
 *
 * A. x 的任何位都等于 1
 * B. x 的任何位都等于 0
 * C. x 的最高有效字节中的位都等于 1
 * D. x 的最低有效字节中的位都等于 0
 *
 * 代码应该遵循位级整数编码规则，另外还有一个限制，你不能使用相等（==）和不相
 * 等（==）测试。
 */

#include <stdio.h>

/*
 * A. !(x+1)
 * B. !x
 * C. !((x & (0xFF << ((sizeof(int)-1) << 3))) + (1 << ((sizeof(int)-1) << 3)))
 * D. !(x & 0xFF)
 */
void ex2_61(void)
{
        int x;
        int w = sizeof(int) << 3;

        /* A. x=111...111 */

        printf("x=111...111 return 1\n");

        x = ~0;
        printf("!(0x%X+1): %s\n", x, !(x+1) ? "right" : "wrong");

        x = 0xFFFFFFFE;
        printf("!(0x%X+1): %s\n", x, !(x+1) ? "right" : "wrong");

        /* B. x=000...000 */

        printf("x=000...000 return 1\n");

        x = 0;
        printf("!0x%X: %s\n", x, !x ? "right" : "wrong");

        x = 1;
        printf("!0x%X: %s\n", x, !x ? "right" : "wrong");

        /* C. 1111 1111 0101 ... 0101 */

        printf("x=_1111 1111_else return 1\n");

        x = 0xFF123456;
        printf("(0x%X & (0xFF << ((sizeof(int)-1) << 3))) + (1 << ((sizeof(int)-1) << 3)): %s\n",
               x, !((x & (0xFF << (w-8))) + (1 << (w-8))) ? "right" : "wrong");

        x = 0xEFFFFFFF;
        printf("(0x%X & (0xFF << ((sizeof(int)-1) << 3))) + (1 << ((sizeof(int)-1) << 3)): %s\n",
               x, !((x & (0xFF << (w-8))) + (1 << (w-8))) ? "right" : "wrong");

        /* D. 1010 0101 ... 0000 0000 */

        printf("x=else..._0000 0000_ return 1\n");

        x = 0x12345600;
        printf("!(0x%X & 0xFF): %s\n", x, !(x & 0xFF) ? "right" : "wrong");

        x = 0x12345601;
        printf("!(0x%X & 0xFF): %s\n", x, !(x & 0xFF) ? "right" : "wrong");
}
