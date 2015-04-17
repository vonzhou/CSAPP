#include "csapp.h"

/* $begin waitprob0 */
int main() 
{
    if (Fork() == 0) {
	printf("a");
    }
    else {
	printf("b");
	waitpid(-1, NULL, 0);
    }
    printf("c");
    exit(0);
}
/* $end waitprob0 */
