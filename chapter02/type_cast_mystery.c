#include <stdio.h>


typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main(){
    short sx = -12345;
    unsigned uy = sx;

    printf("uy = %u:\t", uy);
    show_bytes((byte_pointer)&uy, sizeof(unsigned));
    return 0;
}
