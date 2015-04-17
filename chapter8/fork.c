#include "csapp.h"

int main() 
{
    pid_t pid;
    int x = 1;

    pid = Fork();
    if (pid == 0) {  /* Child */
	    printf("child,pid=%d : x=%d\n",getpid(), ++x);
	    exit(0);
    }

    /* Parent */
    printf("parent,pid=%d: x=%d\n",getpid(), --x); 
    exit(0);
}

