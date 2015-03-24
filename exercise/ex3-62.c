/*
 * 3.62
 */

/*
 * A. M=16
 * B. i: edi, j: ecx
 * C. 如下所示
 */
void transpose(int M, int A[M][M])
{
        int i, j;

        for (i = 0; i < M; i++) {
                int *col = &A[0][i];
                for (j = 0; j < i; j++) {
                        int t = A[i][j];
                        A[i][j] = *col;
                        col += M;
                }
        }
}
