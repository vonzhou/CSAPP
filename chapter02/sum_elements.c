#include <stdio.h>


int sum_elements(float a[], unsigned length){
    int i;
    float result = 0;
    for(i=0; i<=length-1;i++){
        result += a[i];
    }
    return result;
}

int main(){
    int i = 0;
    unsigned len = 0U;
    printf("%u\n", len-1);
    return 0;
}
