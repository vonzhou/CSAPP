/*
 * 练习题 2.74
 *
 * 写出具有如下原型的函数的代码：
 *
 * // Determine whether subtracting arguments will cause overflow
 * int tsub_ovf(int x, int y);
 *
 * 如果计算 x-y 导致溢出，这个函数就返回 1。
 *
 */

#include <limits.h>             /* INT_MIN */

/* Determine whether subtracting arguments will cause overflow */
int tsub_ovf(int x, int y)
{
        int r = x - y;
        int pos_overflow = !(x & INT_MIN) &&  (y & INT_MIN) &&  (r & INT_MIN);
        int neg_overflow =  (x & INT_MIN) && !(y & INT_MIN) && !(r & INT_MIN);

        return pos_overflow || neg_overflow;
}
