/*
 * 11.3
 *
 * mofaph@gmail.com
 * 2013-5-13
 *
 * 编写程序 dd2hex.c，它将它的点分十进制参数转换为十六进制数并打印出结果。例如
 *
 * unix> cc ex11-3.c -o dd2hex
 * unix> ./dd2hex 128.2.194.242
 * 0x8002c2f2
 */

#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
        /* 0. 检查参数是否正确 */
        if (argc != 2) {
                fprintf(stderr, "usage: %s <addr>\n", argv[0]);
                return -1;
        }

        /* 1. 将点分十进制转换成网络字节序的 IP 地址 */
        struct in_addr net;
        int ret = inet_aton(argv[1], &net);
        if (ret == 0) {
                fprintf(stderr, "inet_aton: convert %s failed\n", argv[1]);
                return -1;
        }

        /* 2. 将网络字节序的 IP 地址转换成本地字节序 */
        unsigned int host = ntohl(net.s_addr);

        /* 3. 打印结果 */
        printf("0x%x\n", host);

        return 0;
}
