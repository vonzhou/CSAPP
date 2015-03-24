/*
 * 家庭作业 2.83
 *
 * 填写下列程序的返回值，这个程序是测试它的第一个参数是否大于或者等于第二个参
 * 数。假定函数 f2u 返回一个无符号 32 位数字，其位表示与它的浮点参数相同。你可
 * 以假设两个参数都不是 NaN。两种 0，+0 和 -0 都认为是相等的。
 *
 *      int float_ge(float x, float y) {
 *          unsigned ux = f2u(x);
 *          unsigned uy = f2u(y);
 *
 *          // Get the sign bits
 *          unsigned sx = ux >> 31;
 *          unsigned sy = uy >> 31;
 *
 *          // Given an expression using only ux, uy, sx, sy
 *          return ________;
 *      }
 */

/*
 * 我们用 8 位表示浮点数字，1 位符号位，3 位阶码，4 位小数位。
 *
 * 0 000 0000 +0
 * 0 000 0001 正数最小
 *   .....    递增
 * 0 110 1111 正数最大
 * 0 111 0000 +oo
 * 0 111 0001 NaN
 *   .....
 * 1 000 0000 -0
 * 1 000 0001 负数最大
 *   .....    递减
 * 1 110 1111 负数最小
 * 1 111 0000 -oo
 * 1 111 0001 NaN
 *   .....
 * 1 111 1111 NaN
 *
 * 题目又要求对 +0 和 -0 要做特殊处理（+0 和 -0 应该相等）。也就是位模式 00...0
 * 和 10...0 应该返回 1。
 *
 * 对于符号位为 0 的情况，无符号和浮点数都是正相关的关系（无符号数越大，相应的浮
 * 点表示就越大）。对于符号位为 1 的情况，无符号和浮点数是负相关的关系（无符号数
 * 越大，相应的浮点数越小）。
 *
 * 但是，对于有符号数来说，它和浮点数呈正相关的关系。
 */

int float_ge(float x, float y)
{
        unsigned ux = f2u(x);
        unsigned uy = f2u(y);

        /* Get the sign bits */
        unsigned sx = ux >> 31;
        unsigned sy = uy >> 31;

        /*
         * Give an expression using only ux, uy, sx, and sy
         *
         * The following code should be work, but I'm afraid it doesn't conform
         * to the request.
         *
         * ux+uy==ux-uy && ux+uy==uy-ux ? ux+uy : (int)ux>=(int)uy
         *
         * If ux,uy=[0,INT_MIN], ux+uy==ux-uy && ux+uy==uy-ux should be
         * 1. Otherwise, 0.
         */

        return ux + uy == ux - uy && ux + uy == uy - ux
                ? ux + uy
                : sx ^ sy ? !sx
                          : !sx ? ux >= uy
                                : ux <= uy;
}

/* ftp://202.120.40.101/Courses/Computer_Architecture/csapp.cs.cmu.edu/im/code/data/floatge-ans.c */
int float_ge_ans(float x, float y)
{
        unsigned ux = f2u(x);
        unsigned uy = f2u(y);
        unsigned sx = ux >> 31;
        unsigned sy = uy >> 31;

        return (ux << 1 == 0 && uy << 1 == 0) || /* ux = uy = 0 */
                (!sx && sy) ||                   /* x >= 0, y < 0 */
                (!sx && !sy && ux >= uy) ||      /* x >= 0, y >= 0 */
                (sx && sy && ux <= uy);          /* x < 0, y < 0 */
}
