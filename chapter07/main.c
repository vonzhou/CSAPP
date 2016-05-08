#include <stdio.h>


void swap();

int buf[2] = {1, 2};


static int foo = 99;

int f(){
	static int x = 1;
	return x;
}

int g(){
	static int x = 2;
	return x;
}

int main() 
{
    swap();
    printf("Hello World.\n");
    return 0;
}


