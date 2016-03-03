#include <stdio.h>

// FAKE bis and bic
int bic(int x, int m){
    int mask = ~m;
    return x & mask;
}

int bis(int x, int m){
    return x | m; // bit=1 in m should be set to 1 otherwise no change , so OR
}
//-----------------------------
//
int bool_or(int x, int y){
    return bis(x, y);
}

int bool_xor(int x, int y){
    return bis(bic(x,y), bic(y,x));
}

int main(){
    printf("%d\n", bis(5, 4));
    return 0;
}
