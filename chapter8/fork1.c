#include "csapp.h"

int main() 
{
    Fork();
    printf("ppid=%d,pid=%d\n", getppid(), getpid()); 
    exit(0);
}

