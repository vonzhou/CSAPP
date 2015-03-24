#include <stdio.h>

void bufoverflow(){

	char buf[10];
	gets(buf); // danger .........
	buf[9] = '\0'; // but if we do this , everything will ok!
	printf("%s\n", buf);
	return ;
}

int main(){
	bufoverflow();
	return 0;
}
