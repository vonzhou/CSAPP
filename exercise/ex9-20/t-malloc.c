#include <stdlib.h>

#ifndef MAX_ITEM
#  define MAX_ITEM (1<<17)
#endif

int main(void)
{
        int i;
        char *buf[MAX_ITEM];
        for (i = 1; i < MAX_ITEM; i++) {
                buf[i] = malloc(i);
        }
        for (i = 1; i < MAX_ITEM; i++) {
                free(buf[i]);
        }

        return 0;
}
