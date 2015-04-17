/* $begin sigint1 */
#include "csapp.h"

void handler(int sig) /* SIGINT handler */   //line:ecf:sigint1:beginhandler
{
    printf("Caught SIGINT\n");               //line:ecf:sigint1:printhandler
    exit(0);                                 //line:ecf:sigint1:exithandler
}                                            //line:ecf:sigint1:endhandler

int main() 
{
    /* Install the SIGINT handler */         
    if (signal(SIGINT, handler) == SIG_ERR)  //line:ecf:sigint1:begininstall
	unix_error("signal error");          //line:ecf:sigint1:endinstall
    
    pause(); /* Wait for the receipt of a signal */  //line:ecf:sigint1:pause
    
    exit(0);
}
/* $end sigint1 */
