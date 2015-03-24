/*
 * test ex8-25.c
 *
 * unix> cc ex8-25.c t8-25.c
 */

#include <stdio.h>

/* define in ex8-25.c */
extern char *tfgets(char *s, int size, FILE *stream);

int main(void)
{
        char buf[BUFSIZ];
        char *bufp;

        bufp = tfgets(buf, sizeof(buf), stdin);
        printf("bufp: %p\n", bufp);

        return 0;
}
