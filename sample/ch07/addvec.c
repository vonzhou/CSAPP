/*
 * 这个文件和 multvec.c 用于制作静态库 libvector.a
 *
 * unix> gcc -c addvec.c multvec.c
 * unix> ar rcs libvector.a addvec.o multvec.o
 */

void addvec(int *x, int *y, int *z, int n)
{
        int i;

        for (i = 0; i < n; i++)
                z[i] = x[i] + y[i];
}
