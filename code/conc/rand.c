#include <stdio.h>
#include <stdlib.h>

/* $begin rand */
unsigned int next = 1;

/* rand - return pseudo-random integer on 0..32767 */
int rand(void)
{
    next = next*1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

/* srand - set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
} 
/* $end rand */

int main()
{
    srand(100);
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    exit(0);
}

