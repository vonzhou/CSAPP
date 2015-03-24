/*
 * test ex9-14.c
 *
 * unix> gcc -Wall ex9-14.c t9-14.c
 *
 * mofaph@gmail.com
 */

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern int modify_file_using_mmap(int fd); /* ex9-14.c */

#define HELLO_FILE "t9-14.txt"

int main(void)
{
        int fd = open(HELLO_FILE, O_RDWR);
        if (fd < 0) {
                perror("open");
                return -1;
        }

        int ret = modify_file_using_mmap(fd);
        close(fd);

        return ret;
}
