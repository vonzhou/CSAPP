/*
 * 11.2
 *
 * mofaph@gmail.com
 * 2013-5-13
 *
 * 编写程序 hex2dd.c，它将十六进制参数转换为点分十进制串并打印出结果。例如：
 *
 * unix> cc ex11-2.c -o hex2dd
 * unix> ./hex2dd 0x8002c2f2
 * 128.2.194.242
 */

#include <limits.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
        if (argc != 2) {
                fprintf(stderr, "usage: %s <hex>\n", argv[0]);
                return -1;
        }

        /* 1. 将接收的字符串参数转换成整数 */
        unsigned int host = strtoul(argv[1], NULL, 0);
        if (host == ULONG_MAX && errno == ERANGE) {
                perror("strtoul");
                return -1;
        }

        /* 2. 将数字转换成网络字节序 */
        unsigned int net = htonl(host);

        /* 3. 将整数转换成点分十进制 */
        struct in_addr in;
        in.s_addr = net;
        char *decimal = inet_ntoa(in);
        printf("%s\n", decimal);

        return 0;
}
