/*
 * 10.8
 *
 * mofaph@gmail.com
 * 2013-5-11
 *
 * 编写图 10-10 中的 statcheck 程序的一个版本，叫做 fstatcheck，它从命令行取得一
 * 个描述符数字而不是文件名。
 *
 * $ cc -I../common ../common/csapp.c ex10-8.c -lpthread
 */

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        if (argc != 2) {
                fprintf(stderr, "usage: %s fd\n", argv[0]);
                return -1;
        }

        char *c = argv[1];
        for (;;) {
                if (isalpha(*c)) {
                        fprintf(stderr, "%s: not a number\n", argv[1]);
                        return -1;
                }
                if (*c == '\0')
                        break;
                c += 1;
        }

        int fd = atoi(argv[1]);
        struct stat stat;
        int ret = fstat(fd, &stat);
        if (ret) {
                perror("fstat");
                return -1;
        }

        char *type;
        if (S_ISREG(stat.st_mode)) /* Determine file type */
                type = "regular";
        else if (S_ISDIR(stat.st_mode))
                type = "directory";
        else
                type = "other";

        char *readok;
        if ((stat.st_mode & S_IRUSR)) /* Check read access */
                readok = "yes";
        else
                readok = "no";

        printf("type: %s, read: %s\n", type, readok);
        exit(0);
}
