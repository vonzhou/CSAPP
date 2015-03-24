/*
 * 家庭作业 2.75
 *
 * 假设我们想要计算 x·y 的完整的 2w 位表示，其中，x 和 y 都是无符号数，并且运
 * 行在数据类型 unsigned 是 w 位的机器上。乘积的低 w 位能够用表达式 x·y 计算，
 * 所以，我们只需要一个具有下列原型的函数：
 *
 * unsigned unsigned_high_prod(unsigned x, unsigned y);
 *
 * 这个函数计算无符号变量 x·y 的高 w 位。
 * 我们使用一个具有下面原型的库函数：
 *
 * int signed_high_prod(int x, int y);
 *
 * 它计算在 x 和 y 采用补码形式的情况下，x·y 的高 w 位。编写代码调用这个过程，
 * 以实现用无符号数为参数的函数。验证你的解答的正确性。
 *
 * 提示：看看等式（2-18）的推导中，有符号乘积 x·y 和无符号乘积 x'·y' 之间的关
 * 系。
 */
#include <limits.h>             /* INT_MIN */

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
        int x_highest_bit = (x & INT_MIN) == INT_MIN;
        int y_highest_bit = (y & INT_MIN) == INT_MIN;

        int result = signed_high_prod(x, y) + x * y_highest_bit + y * x_highest_bit;
        return result;
}
