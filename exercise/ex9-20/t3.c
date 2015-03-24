#include <stdio.h>

int main(void)
{
        char s[10];
        do {
                printf("Input: ");
                scanf("%s", s);
                printf("Output: %s\n", s);

        } while (s[0] != 'q');

        return 0;
}
