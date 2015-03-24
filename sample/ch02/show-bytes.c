/*
 * p28 -- code/data/show-bytes.c
 *
 * 打印程序对象的字节表示。这段代码使用强制类型转换来规避类型系统。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
        int i;
        for (i = 0; i < len; i++)
                printf(" %.2x", start[i]);
        printf("\n");
}

void show_int(int x)
{
        show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
        show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
        show_bytes((byte_pointer) &x, sizeof(void *));
}
