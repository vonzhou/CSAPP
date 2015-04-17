/* $begin restart */
#include "csapp.h"

sigjmp_buf buf;

void handler(int sig) 
{
    siglongjmp(buf, 1);
}

int main() 
{
    Signal(SIGINT, handler);

    if (!sigsetjmp(buf, 1)) 
	printf("starting\n");
    else 
	printf("restarting\n");

    while(1) {
	Sleep(1);
	printf("processing...\n");
    }
    exit(0);
}
/* $end restart */
