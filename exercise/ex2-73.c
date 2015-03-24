/*
 * 练习题 2.73
 *
 * Addition that saturates to TMin or TMax
 *
 * 通正常的补码溢出的方式不同，当正溢出时，saturating_add 返回 TMax，负溢出时，返
 * 回 TMin。这种运算常常用在执行数字信号处理的程序中。
 *
 * 你的函数应该遵循位级整数编码规则。
 *
 * 通过观察研究（其实想了很久），我们发现，对于不同的情况，补码加法的结果如下：
 *
 * (r |       0) +       0      正常
 * (r | INT_MAX) + INT_MIN      正溢出
 * (r | INT_MAX) +       1      负溢出
 *
 *       0 = INT_MIN + INT_MAX + 1 + 0
 * INT_MIN = INT_MIN +       0 + 0 + 0
 *       1 = INT_MIN + INT_MAX + 1 + 1
 *
 * 观察上面的等式。在等号右边的第二栏，当正溢出时为 0，不是正溢出时是 INT_MAX。观
 * 察第三栏，当正溢出时是 0，不是正溢出时是 1。观察第三栏，当负溢出时是 1，不是负
 * 溢出时是 0。
 *
 * 注意：在下面的代码中，当变量名为 xxx_when_condition 有两种取值。当条件不满足时
 * 是 0，当条件满足时是 1。
 */

#include <limits.h>             /* INT_MAX, INT_MIN */

int saturating_add(int x, int y)
{
        int r = x + y;
        int pos_overflow = !(x & INT_MIN) && !(y & INT_MIN) && (r & INT_MIN);
        int neg_overflow = (x & INT_MIN) && (y & INT_MIN) && !(r & INT_MIN);
        int TMax_when_overflow = INT_MAX & (INT_MIN - (pos_overflow | neg_overflow));
        int TMax_when_not_pos_overflow = (INT_MAX & (INT_MIN - !pos_overflow));
        int bias = INT_MIN + TMax_when_not_pos_overflow + !pos_overflow + neg_overflow;

        return (r | TMax_when_overflow) + bias;
}
