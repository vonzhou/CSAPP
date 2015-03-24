/*
 * 9.14
 *
 * 假设有一个输入文件 hello.txt，由字符串“Hello, world!\n”组成，编写一个 C 程序，
 * 使用 mmap 将 hello.txt 的内容改为“Jello, world!\n”。
 *
 * unix> gcc -Wall ex9-14.c t9-14.c
 *
 * mofaph@gmail.com
 */

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int modify_file_using_mmap(int fd)
{
        struct stat st;
        int ret = fstat(fd, &st);
        if (ret) {
                perror("fstat");
                return -1;
        }

        void *map_addr = mmap(NULL, st.st_size, PROT_WRITE, MAP_SHARED, fd, 0);
        if (map_addr == MAP_FAILED) {
                perror("mmap");
                return -1;
        }

        char *buf = map_addr;
        *buf = 'J';

        return 0;
}
