/*
 * 练习题 2.81
 *
 * 我们在一个 int 类型值为 32 位的机器上运行程序。这些值以补码形式表示，而且它们
 * 都是算术右移的。unsigned 类型的值也是 32 位的。
 *
 * 我们产生随机数 x 和 y，并且把它们转换成无符号数，显示如下：
 *
 * // Create some arbitrary values
 * int x = random();
 * int y = random();
 * // Convert to unsigned
 * unsigned ux = (unsigned) x;
 * unsigned uy = (unsigned) y;
 *
 * 对于下列每个 C 表达式，你要指出表达式是否总是为 1。如果它总是为 1，那么请描
 * 述其中的数学原理。否则，列举一个使它为 0 的参数示例。
 *
 * A. (x > y) == (-x < -y)
 * B. ((x + y) << 5) + x - y == 31 * y + 33 * x
 * C. ~x + ~y == ~(x + y)
 * D. (int)(ux - uy) == -(y - x)
 * E. ((x >> 1) << 1) <= x
 *
 */

#include <limits.h>             /* INT_MIN */
#include <stdlib.h>             /* random() */
#include <stdio.h>              /* printf() */

int main(void)
{
        /* Create some arbitrary values */
        int x = random();
        int y = random();

        /* Convert to unsigned */
        unsigned ux = (unsigned)x;
        unsigned uy = (unsigned)y;

        /*
         *  A. (x > y) == (-x < -y)
         *
         *  当 y=INT_MIN 时，这个表达式为 0
         */
        printf("(x > INT_MIN) == (-x < -INT_MIN): %d\n", (x > INT_MIN) == (-x < -INT_MIN));

        /*
         * B. ((x + y) << 5) + x - y == 31 * y + 33 * x
         *
         * 这个表达式求值为 1
         *
         * 补码加减法符合基本的数学原理
         */
        printf("((x + y) << 5) + x - y == 31 * y + 33 * x: %d\n", ((x + y) << 5) + x - y == 31 * y + 33 * x);

        /*
         * C. ~x + ~y == ~(x + y)
         *
         * 这个表达式求值为 0
         *
         * ~x = 2^w - x - 1
         * ~y = 2^w - y - 1
         * ~x + ~y = 2^(w+1) - x - y -2
         *
         * ~(x+y) = 2^w - x - y - 1
         */
        printf("~x + ~y == ~(x + y): %d\n", ~x + ~y == ~(x + y));

        /*
         * D. (int)(ux - uy) == -(y - x)
         *
         * 这个表达式求值为 1
         *
         * 对于任意的数字 a，有如下的等式成立：
         *
         *     -a = ~a + 1 = 2^w - a
         *
         * -(y - x) = 2^w - (y - x) = 2^w + x - y
         * 对于 w 位补码，算术运算的结果截断为 w 位。
         *
         * ux - uy == 2^w + x - y
         */
        printf("(int)(ux - uy) == -(y - x): %d\n", (int)(ux - uy) == -(y - x));

        /*
         * E. ((x >> 1) << 1) <= x
         *
         * 这个表达式值为 1
         *
         * 因为右移会将最低位置零，如果最低位是 1 的话，那么左移回来就会小于移位
         * 之前的数；如果最低位是 0 的话，那么左移回来的数就会等于移位之前的数。
         */
        printf("((x >> 1) << 1) <= x: %d\n", ((x >> 1) << 1) <= x);

        return 0;
}
