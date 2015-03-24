/*
 * 查询和处理一个文件的 st_mode 位
 *
 * $ cc -I../../common statcheck.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

int main(int argc, char **argv)
{
        struct stat stat;
        char *type, *readok;

        Stat(argv[1], &stat);

        if (S_ISREG(stat.st_mode)) /* Determine file type */
                type = "regular";
        else if (S_ISDIR(stat.st_mode))
                type = "directory";
        else
                type = "other";

        if ((stat.st_mode & S_IRUSR)) /* Check read access */
                readok = "yes";
        else
                readok = "no";

        printf("type: %s, read: %s\n", type, readok);
        exit(0);
}
