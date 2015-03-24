/*
 * p523 -- code/ecf/setjmp.c
 *
 * 非本地跳转的一个重要应用就是允许从一个深层嵌套的函数调用中立即返回，通常是由检
 * 测到某个错误情况引起的。如果在一个深层嵌套的函数调用中发现了一个错误，我们可以
 * 使用非本地跳转直接返回到一个普通的本地化的错误处理程序，而不是费力地解开调用栈
 *
 * 这个示例程序说明了非本地跳转将是如何工作的。main() 首先调用 setjmp() 以保存当
 * 前的调用环境，然后调用 foo()，foo() 一次调用 bar()。如果 foo() 或 bar() 遇到一
 * 个错误，它们立即通过一次 longjmp() 调用从 setjmp() 返回。setjmp() 的非零返回值
 * 指明了错误类型，随后可以被解码，且在代码中的某个位置进行处理。
 *
 * unix> gcc -I../../common setjmp.c ../../common/csapp.c -lpthread
 */

#include "csapp.h"

jmp_buf buf;

int error1 = 0;
int error2 = 1;

void foo(void), bar(void);

int main()
{
        int rc;

        rc = setjmp(buf);
        if (rc == 0)
                foo();
        else if (rc == 1)
                printf("Detected an error1 condition in foo\n");
        else if (rc == 2)
                printf("Detected an error2 condition in foo\n");
        else
                printf("Unknown error condition in foo\n");
        exit(0);
}

/* Deeply nested function foo */
void foo(void)
{
        if (error1)
                longjmp(buf, 1);
        bar();
}

void bar(void)
{
        if (error2)
                longjmp(buf, 2);
}
