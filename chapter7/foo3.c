#include <stdio.h>

void f();

int x = 15213; // strong

int main(){
	f();
	printf("x=%d\n", x);
	return 0;
}
