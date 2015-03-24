/*
 * 使用 read/write 一次一个字节地从标准输入拷贝到标准输出
 *
 * $ cc -I../../common cpstdin.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

int main(void)
{
        char c;

        while (Read(STDIN_FILENO, &c, 1) != 0)
                Write(STDOUT_FILENO, &c, 1);

        exit(0);
}
