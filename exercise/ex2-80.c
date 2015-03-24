/*
 * 家庭作业 2.80
 *
 * 编写 C 表达式产生如下位模式，其中 a^n 表示符号 a 重复 n 次。假设一个 w 位的
 * 数据类型。你的代码可以包含对参数 m 和 n 的引用，它们分别表示 m 和 n 的值，但
 * 是不能使用表示 w 的参数。
 *
 * A. 1^(w-n)0^n
 * B. 0^(w-n-m)1^n0^m
 */

/*
 * A. ~((1 << n) - 1)
 */
int nlowest_zero(int n)
{
        return ~((1 << n) - 1);
}

/*
 * B. ((1 << n) - 1) - ((1 << m) - 1) = (1 << n) - (1 << m)
 */
int nlowestone_minus_mlowestone(int n, int m)
{
        return (1 << (m + n)) - (1 << m);
}
