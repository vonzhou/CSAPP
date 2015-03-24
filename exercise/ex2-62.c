/*
 * 练习题 2.62
 *
 * 编写一个函数 int_shifts_are_logical()，在对 int 类型的数使用算术右移的机器上运
 * 行时，这个函数生成 1，而其他情况下生成 0。你的代码应该可以运行在任何字长的机器
 * 上。在几种机器上测试你的代码。
 */

#include <limits.h>

int int_shifts_are_logical(void)
{
        int x = (~0 - 1) >> 1;

        return x != INT_MAX;
}
