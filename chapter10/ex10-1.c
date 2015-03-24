/*
 *P598 , 10.1
 */

#include "csapp.h"

int main()
{
        int fd1, fd2;
        char c;

        fd1 = Open("foobar.txt", O_RDONLY, 0);
		Close(fd1);
        fd2 = Open("baz.txt", O_RDONLY, 0);
    	    
		printf("fd2 = %d\n", fd2);
        exit(0);
}
