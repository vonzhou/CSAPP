#include "csapp.h"

int *matvec1(int **A, int *x, int n){
	int i,j;
	int *y = Malloc(n * sizeof(int));
	
	for(i=0; i<n ;i++)
		y[i] = 0;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			y[i] += A[i][j] * x[j];
		}
	return y;
}

int *matvec2(int A[][3], int *x, int n){
	int i,j;
	int *y = Malloc(n * sizeof(int));
	
	for(i=0; i<n ;i++)
		y[i] = 0;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			y[i] += A[i][j] * x[j];
		}
	return y;
}

int *matvec3(int (*A)[3], int *x, int n){
	int i,j;
	int *y = Malloc(n * sizeof(int));
	
	for(i=0; i<n ;i++)
		y[i] = 0;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			y[i] += A[i][j] * x[j];
		}
	return y;
}

int *matvec4(int *A, int *x, int n){
	int i,j;
	int *y = Malloc(n * sizeof(int));
	
	for(i=0; i<n ;i++)
		y[i] = 0;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			y[i] += A[i*n + j] * x[j];
		}
	return y;
}

int main(){
	int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int x[3] = {2,3,4};
	int i, n  = 3;

	int *y = NULL;
	//y = matvec3(A, x, n);
	y = matvec4(&A[0][0], x, 3);
	printf("Ax = [");
	for(i=0; i<n ;i++)
		printf("%d," , y[i]);
	printf("]\n");


	free(y);
	return 0;
}
