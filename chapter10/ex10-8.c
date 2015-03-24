/*
 * p612, 10.8
 */
#include "csapp.h"

int main(int argc, char **argv)
{
        if (argc != 2) {
                fprintf(stderr, "usage: %s fd\n", argv[0]);
                return -1;
        }

		// 有效性检查
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
