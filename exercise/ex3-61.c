/*
 * 3.61
 *
 * $ gcc -O2 -S ex3-61.c # 这样就不会使循环的值溢出到存储器了
 */

/* Compute i,k of variable matrix product */
int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k)
{
        int j;
        int result = 0;

        void *Arow = (void *)&A[i][0];
        void *Bcol = (void *)&B[0][k];

        int N = 4 * n;
        for (j = 0; j < N; j += 4)
                result += *(int *)(Arow + j) * *(int *)(Bcol + N);

        return result;
}
