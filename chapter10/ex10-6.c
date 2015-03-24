/*
 * P612, 习题10.6
 */

#include "csapp.h"

int main(void)
{
        int fd1, fd2;

        fd1 = Open("foobar.txt", O_RDONLY, 0); /* fd1: 3 */
        fd2 = Open("baz.txt", O_RDONLY, 0); /* fd2: 4 */
        Close(fd2);
        fd2 = Open("baz.txt", O_RDONLY, 0); /* fd2: 4 */
        printf("fd2 = %d\n", fd2);
        exit(0);
}
