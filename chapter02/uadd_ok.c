#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y){
    unsigned sum = x + y;
    return sum >= x;
}

int main(){
    printf("ok ? = %d\n" , uadd_ok(1U, UINT_MAX));
    return 0;
}
