/*
 * 这个文件用于演示静态库的使用
 *
 * 在使用之前，我们需要生成 libvector.a
 *
 * unix> gcc -O2 -c main2.c
 * unix> gcc -static -o p2 main2.o ./libvector.a
 */

#include <stdio.h>
#include "vector.h"

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main()
{
        addvec(x, y, z, 2);
        printf("z = [%d %d]\n", z[0], z[1]);
        return 0;
}
