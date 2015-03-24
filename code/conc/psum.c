/* 
 * psum.c - A simple parallel sum program
 */
/* $begin psum */
#include "csapp.h"
#define MAXTHREADS 32    

void *sum(void *vargp);

/* Global shared variables */
long psum[MAXTHREADS];  /* Partial sum computed by each thread */
long nelems_per_thread; /* Number of elements summed by each thread */

int main(int argc, char **argv) 
{
    long i, nelems, log_nelems, nthreads, result = 0;
    pthread_t tid[MAXTHREADS];
    int myid[MAXTHREADS];

    /* Get input arguments */
    if (argc != 3) {
	printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
	exit(0);
    }
    nthreads = atoi(argv[1]);
    log_nelems = atoi(argv[2]);
    nelems = (1L << log_nelems);
    /* $end psum */
    /* Check input arguments */
    if  ((nelems % nthreads) != 0 || (log_nelems > 31)) {
	printf("Error: invalid nelems\n");
	exit(0);
    }
    /* $begin psum */
    nelems_per_thread = nelems / nthreads;

    /* Create peer threads and wait for them to finish */
    for (i = 0; i < nthreads; i++) {                  //line:conc:psum:createloop1
	myid[i] = i;                                  //line:conc:psum:createloop2
	Pthread_create(&tid[i], NULL, sum, &myid[i]); //line:conc:psum:createloop3
    }                                                 //line:conc:psum:createloop4
    for (i = 0; i < nthreads; i++)                    //line:conc:psum:waitloop1
	Pthread_join(tid[i], NULL);                   //line:conc:psum:waitloop2
    
    /* Add up the partial sums computed by each thread */
    for (i = 0; i < nthreads; i++)                    //line:conc:psum:sumloop1
	result += psum[i];                            //line:conc:psum:sumloop2

    /* Check final answer */
    if (result != (nelems * (nelems-1))/2)     //line:conc:psum:check1
	printf("Error: result=%ld\n", result); //line:conc:psum:check2

    exit(0);
}
/* $end psum */

/* Thread routine */
/* $begin psum-thread */
void *sum(void *vargp) 
{
    int myid = *((int *)vargp);            /* Extract the thread ID */ //line:conc:psum:extractid
    long start = myid * nelems_per_thread; /* Start element index */ //line:conc:psum:getstart
    long end = start + nelems_per_thread;  /* End element index */ //line:conc:psum:getend
    long i, sum = 0;

    for (i = start; i < end; i++) {        //line:conc:psum:threadsumloop1
	sum += i;                          //line:conc:psum:threadsumloop2 
    }	                                   //line:conc:psum:threadsumloop3
    psum[myid] = sum; //line:conc:psum:threadsum             

    return NULL;
}
/* $end psum-thread */

