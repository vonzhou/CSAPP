#include <stdio.h>
#include <string.h>

int stronger(char *s, char *t){
    return strlen(s) - strlen(t) > 0;
    // return strlen(s) > strlen(t);
}

int main(){
    char *s = "abc";
    char *t = "abcdef";
    printf("stringer = %d\n", stronger(s,t));
    return 0;
}
