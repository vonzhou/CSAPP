/*
 * 8.4 -- code/ecf/waitprob1.c
 *
 * A. 这个程序会产生多少输出行？
 * B. 这些输出行的一种可能的顺序是什么？
 *
 * 个人解答在文件末尾
 *
 * 编译运行：
 *
 * $ gcc -iquote../../common ex8-4.c ../../common/csapp.c -lpthread
 */

#include <stdio.h>

#include "csapp.h"

int main()
{
        int status;
        pid_t pid;

        printf("Hello\n");
        pid = Fork();
        printf("%d\n", !pid);
        if (pid != 0)
                if (waitpid(-1, &status, 0) > 0)
                        if (WIFEXITED(status) != 0)
                                printf("%d\n", WEXITSTATUS(status));
        printf("Bye\n");
        exit(2);
}




































































/*
 * A. 6
 *
 * B. Hello/0/1/Bye/2/Bye
 *    Hello/1/Bye/0/2/Bye
 *    Hello/1/0/Bye/2/Bye
 */
