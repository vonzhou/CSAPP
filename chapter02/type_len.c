#include <stdio.h>

int main(){
    int x = 10;
    int *p = &x;
    printf("char=%d, short=%d, int=%d, long=%d, float=%d, double=%d, pointer=%d\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(float), sizeof(double), sizeof(p));
    return 0;
}
