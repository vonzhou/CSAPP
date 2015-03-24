/*
 * 练习题 2.36
 *
 * 对于数据类型 int 为 32 位的情况，设计一个版本的 tmult_ok 函数（见练习题 2.35），
 * 要使用 64 位精度的数据类型 long long，而不使用除法。
 */

/*
 * Determine whether arguments can be multipled without overflow
 *
 * overflow: 0, normal: 1
 */
int tmult_ok(int x, int y)
{
        long long result = (long long)x * (long long)y;
        int iresult = x * y;

        return result == iresult;
}

int book_tmult_ok(int x, int y)
{
        /* Compute product without overflow */
        long long pll = (long long)x * y;
        /* See if casting to int preserves value */
        return pll == (int)pll;
}
