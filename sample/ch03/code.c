/*
 * p107
 *
 * 使用 GCC 产生汇编代码：
 *     unix> gcc -O1 -S code.c
 *
 * 使用 GCC 产生目标代码文件：
 *     unix> gcc -O1 -c code.c
 */

int accum = 0;

int sum(int x, int y)
{
        int t = x + y;
        accum += t;
        return t;
}
