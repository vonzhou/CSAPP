#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        struct free_block {
                char *addr;
                long size;
        };

        struct free_block *s, *e;
        long s1 = 0x8040a0a0;
        long s2 = s1 + 9*sizeof(struct free_block);

        s = (struct free_block *)s1;
        e = (struct free_block *)s2;
        printf("e: %p, s: %p, e-s: %d\n", e, s, e-s);

        return 0;
}
