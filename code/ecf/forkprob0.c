/* $begin forkprob0 */
#include "csapp.h"

int main() 
{
    int x = 1;

    if (Fork() == 0)
	printf("printf1: x=%d\n", ++x);
    printf("printf2: x=%d\n", --x);
    exit(0);
}
/* $end forkprob0 */

