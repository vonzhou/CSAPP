#include <stdio.h>

int foo = 0;
static int bar = 100;

int f(){
	static int x = 1;
	return x;
}

int g(){
	static int x =2;
	return x;
}


int main(){
	f();
	g();
	return 0;
}




