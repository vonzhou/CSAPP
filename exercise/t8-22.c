/*
 * 8.22
 *
 * unix> cc ex8-22.c t8-22.c
 */

#include <stdio.h>

extern int mysystem(char *command); /* ex8-22.c */

int main(int argc, char *argv[])
{
        return mysystem(argv[1]);
}
