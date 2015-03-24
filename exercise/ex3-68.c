/*
 * 3.68
 *
 * mofaph@gmail.com
 */

#include <stdio.h>

#define MAX_INPUT 5             /* 以小一点的数字，使问题可以方便地出现（如果有的话） */

int good_echo(void)
{
        char s[MAX_INPUT];
        char *ret;

        ret = fgets(s, sizeof(s), stdin);
        if (ret == NULL) {
                if (!feof(stdin)) /* 输入错误 */
                        return -1;
                goto done;      /* 输入了 EOF */
        }

        int out;
        out = fputs(s, stdout);
        if (out == EOF)
                return -1;      /* 输出错误 */

done:
        return 0;
}
