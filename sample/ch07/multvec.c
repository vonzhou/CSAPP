/*
 * 这个文件用于制作 libvector.a 静态库，具体方法见 addvec.c
 */

void multvec(int *x, int *y, int *z, int n)
{
        int i;

        for (i = 0; i < n; i++)
                z[i] = x[i] * y[i];
}
