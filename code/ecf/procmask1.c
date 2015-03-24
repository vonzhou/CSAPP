#include "csapp.h"

void initjobs()
{
}

void addjob(int pid)
{
}

void deletejob(int pid)
{
}

/* $begin procmask1 */
void handler(int sig)
{
    pid_t pid;
    while ((pid = waitpid(-1, NULL, 0)) > 0) /* Reap a zombie child */
	deletejob(pid); /* Delete the child from the job list */
    if (errno != ECHILD)
	unix_error("waitpid error");
}
    
int main(int argc, char **argv)
{
    int pid;

    Signal(SIGCHLD, handler);
    initjobs(); /* Initialize the job list */

    while (1) {
	/* Child process */
	if ((pid = Fork()) == 0) {
	    Execve("/bin/date", argv, NULL);
	}

	/* Parent process */
	addjob(pid);  /* Add the child to the job list */
    }
    exit(0);
}
/* $end procmask1 */
