
#include <stdio.h>

void inplace_swap(int *x, int *y){
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

int main(){
    int x = 10;
    int y = 99999;
    printf("x=%d,y=%d\n", x, y);
    inplace_swap(&x, &y);
    printf("x=%d,y=%d\n", x,y);
    return 0;
}
