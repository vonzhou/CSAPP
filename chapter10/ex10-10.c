/*
 * 10.10
 * 因为题目中暗示了只能插入代码 不能更改存在的代码
 */

#include "csapp.h"

int main(int argc, char **argv)
{
        int n;
        rio_t rio;
        char buf[MAXLINE];

        if (argc > 2) {
                fprintf(stderr, "usage: %s [filename]\n", argv[0]);
                return -1;
        }

        /* 这里将标准输入的文件描述符，重定位到输入文件的描述符 */
        if (argc == 2) {
                char *filename = argv[1];
                int fd = Open(filename, O_RDONLY, 0);
                int ret = dup2(fd, STDIN_FILENO); /* 将标准输入重定位到 fd */
                if (ret < 0) {
                        perror("dup2");
                        return -1;
                }
        }

        /* 没有输入文件名，将标准输入拷贝到标准输出 */
        Rio_readinitb(&rio, STDIN_FILENO);
        while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
                Rio_writen(STDOUT_FILENO, buf, n);

        return 0;
}
