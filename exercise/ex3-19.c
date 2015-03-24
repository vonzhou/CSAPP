/*
 * 练习题 3.19
 *
 * A. 用一个 32 位 int 表示 n!，最大的 n 的值是多少？
 * B. 如果用一个 64 位 long long int 表示，最大的 n 的值是多少？
 */

/*
 * Return 1 when OK, otherwise return 0
 */
int tmul_ok_32(int x, int y)
{
        int p = x * y;
        return !x || p / x == y;
}

/*
 * A solution
 */
int largest_factorial_32(void)
{
        int result = 1;
        int n = 1, overflow;

        for (;;) {
                n++;
                overflow = !tmul_ok_32(result, n);
                if (overflow)
                        break;
                result *= n;
        }

        return n - 1;
}

int tmul_ok_64(long long int x, long long int y)
{
        long long int p = x * y;
        return !x || p / x == y;
}

/*
 * B solution
 */
int largest_factorial_64(void)
{
        long long int result = 1;
        int n = 1, overflow;

        for (;;) {
                n++;
                overflow = !tmul_ok_64(result, n);
                if (overflow)
                        break;
                result *= n;
        }

        return n - 1;
}
