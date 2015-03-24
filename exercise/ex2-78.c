/*
 * 家庭作业 2.78
 *
 * 写出函数 mul5div8 的代码，对于整数参数 x，计算 5*x/8，但是要遵循位级整数编
 * 码规则。你的代码计算 5*x 也会产生溢出。
*/

#include <limits.h>

int mul5div8(int x)
{
        int sign = (x & INT_MIN) == INT_MIN;
        int bias = (7 + !sign) & 7;
        int t = (x << 2) + x;
        return (t + bias) >> 3;
}
