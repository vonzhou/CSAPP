/* 
 * hellobug.c - "hello, world" program with a bug
 */
/* $begin hellobug */
#include "csapp.h"
void *thread(void *vargp);

int main() 
{
    pthread_t tid;

    Pthread_create(&tid, NULL, thread, NULL);
    exit(0);
}

/* thread routine */
void *thread(void *vargp) 
{
    Sleep(1);
    printf("Hello, world!\n"); 
    return NULL;
}
/* $end hellobug */
