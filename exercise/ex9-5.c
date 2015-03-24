/*
 * 9.5
 *
 * 使用 mmap() 将一个任意大小的磁盘文件拷贝到 stdout。
 * 输入文件的名字必须作为一个命令行参数来传递。
 *
 * unix> cc ex9-5.c -o mmapcopy
 *
 * #include <unistd.h>
 * #include <sys/mman.h>
 *
 * void *mmap(void *start, size_t length, int prot, int flags,
 *            int fd, off_t offset);
 */

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
        int n, fd;
        void *map;
        struct stat statbuf;

        if (argc != 2) {
                fprintf(stderr, "usage: %s <filename>\n", argv[0]);
                exit(1);
        }

        fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
                perror("open");
                exit(1);
        }
        if (fstat(fd, &statbuf) != 0) {
                perror("fstat");
                exit(1);
        }

        map = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (map == MAP_FAILED) {
                perror("mmap");
                exit(1);
        }
        if (close(fd) < 0) {
                perror("close");
                exit(1);
        }
        n = write(STDOUT_FILENO, map, statbuf.st_size);
        if (n != statbuf.st_size) {
                perror("write");
                exit(1);
        }

        return 0;
}
