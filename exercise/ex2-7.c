/*
 * 编译方法：
 *     $ cc ex2-7.c ../show-bytes.c
 */

#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

extern void show_bytes(byte_pointer start, int len);

int main(void)
{
        const char *s = "abcdef";
        show_bytes((byte_pointer)s, strlen(s));

        return 0;
}
