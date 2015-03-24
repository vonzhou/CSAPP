/*
 * 8.26
 *
 * mofaph@gmail.com
 * 2013-7-14
 *
 * 测试 job.c
 *
 * unix> cc -Wall t-job.c job.c -o t-job
 */

#include <stdio.h>
#include <string.h>

#include "job.h"

#define MAXLINE 1024

int main(void)
{
        char buf[MAXLINE];
        init_job();

        pid_t pgid;
        int state;
        char command[MAXLINE];
        do {
                printf("[A]dd/[D]elete/[P]rint/[Q]uit/[S]et_fg/[F]g/[B]g/[p]rint_fg?\n");
                fgets(buf, sizeof(buf), stdin);
                switch (buf[0]) {
                case 'A':
                        printf("pgid state command: ");
                        fflush(stdin);
                        scanf("%d %d %s", &pgid, &state, command);
                        add_job(pgid, state, command, MAXLINE);
                        printf("Add job %d to job list\n", (int)pgid);
                        break;
                case 'D':
                        print_all_job();
                        printf("JID? ");
                        scanf("%d", &pgid);
                        delete_job((int)pgid);
                        break;
                case 'P':
                        print_all_job();
                        break;
                case 'S':
                        printf("pgid command: ");
                        fflush(stdin);
                        scanf("%d %s", &pgid, command);
                        set_foreground(pgid, command, MAXLINE);
                        break;
                case 'p':
                        print_foreground();
                        break;
                case 'F':
                        print_all_job();
                        printf("JID? ");
                        scanf("%d", &pgid);
                        move_to_foreground(pgid);
                        break;
                case 'B':
                        printf("pgid state command: ");
                        fflush(stdin);
                        scanf("%d %d %s", &pgid, &state, command);
                        int len = strlen(command) + 1;
                        move_to_background(pgid, state, command, len);
                        break;
                default:
                        break;
                }
        } while (buf[0] != 'Q');

        free_job();
        return 0;
}
