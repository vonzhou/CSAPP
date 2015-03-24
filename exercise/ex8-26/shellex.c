/*
 * 8.26
 *
 * mofaph@gmail.com
 * 2013-7-7
 *
 * unix> make
 * unix> ./t
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#include "job.h"

extern pid_t random_fork(void);

#define MAXLINE 4096
#define MAXARGS 128

extern char **environ;

void reap_child(int signo)
{
        for (;;) {
                /* We don't care child's terminated status */
                int status;
                int ret = waitpid(-1, &status, WNOHANG);
                if (ret == 0) { /* child didn't terminated, return immediately */
                        break;
                } else if (ret < 0 && errno == ECHILD) /* no child */ {
                        break;
                } else if (ret > 0) {
                        if (WIFSIGNALED(status))
                                printf("Job %d terminated by signal: %s\n", ret, strsignal(WTERMSIG(status)));
                        delete_job(ret);
                } else {
                        /* nothing */;
                }
        }
}

void wait_for_job(pid_t pgid)
{
        int status;
        int ret = waitpid(-pgid, &status, WUNTRACED);
        if (ret == -1) {
                perror("waitpid");
                return;
        }
        /* Child stopped or terminated */
        if (WIFSTOPPED(status)) {
                printf("Job %d stopped by signal: %s\n", (int)pgid, strsignal(WSTOPSIG(status)));
        } else if (WIFSIGNALED(status)) {
                printf("Job %d terminated by signal: %s\n", (int)pgid, strsignal(WTERMSIG(status)));
                delete_job(pgid);
        } else {
                delete_job(pgid);
        }
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv)
{
        if (!strcmp(argv[0], "quit")) {
                exit(0);
        } else if (!strcmp(argv[0], "bg") || !strcmp(argv[0], "fg")) {
                int jid;
                pid_t pgid;
                char *p = argv[1];
                if (*p == '%') {
                        p += 1;
                        jid = atoi(p);
                        pgid = get_pgid(jid);
                        if (pgid < 0) {
                                fprintf(stderr, "%d: No such job\n", jid);
                                return 1;
                        }
                } else {
                        pgid = atoi(p);
                }
                kill(-pgid, SIGCONT);
                if (!strcmp(argv[0], "fg")) {
                        move_to_foreground(pgid);
                        print_foreground();
                        wait_for_job(pgid);
                } else {
                        update_job(pgid, JOB_RUNNING);
                }
                return 1;
        } else if (!strcmp(argv[0], "jobs")) {
                print_all_job();
                return 1;
        } else if (!strcmp(argv[0], "&")) { /* Ignore singleton & */
                return 1;
        } else {
                return 0;       /* Not a builtin command */
        }
}

/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv)
{
        char *delim;            /* Points to first space delimiter */
        int argc;               /* Number of args */
        int bg;                 /* Background job? */

        buf[strlen(buf)-1] = ' ';     /* Replace trailing '\n' with space */
        while (*buf && (*buf == ' ')) /* Ignore leading spaces */
                buf++;

        /* Build the argv list */
        argc = 0;
        while ((delim = strchr(buf, ' '))) {
                argv[argc++] = buf;
                *delim = '\0';
                buf = delim + 1;
                while (*buf && (*buf == ' ')) /* Ignore spaces */
                        buf++;
        }
        argv[argc] = NULL;

        if (argc == 0)          /* Ignore blank line */
                return 1;

        /* Should the job run in the background? */
        if ((bg = (*argv[argc-1] == '&')) != 0)
                argv[--argc] = NULL;

        return bg;
}

void run_the_job(char *filename, char *argv[], char *env[])
{
        int ret = setpgid(0, 0);
        if (ret < 0) {
                fprintf(stderr, "Failed to set group process id\n");
                exit(-1);
        }
        if (execve(argv[0], argv, env) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
        }
}

/* eval - Evaluate a command line */
void eval(char *cmdline)
{
        char buf[MAXLINE];      /* Holds modified command line */
        strcpy(buf, cmdline);
        char *argv[MAXARGS];           /* Argument list execve() */
        int bg = parseline(buf, argv); /* Should the job run in bg or fg? */
        if (argv[0] == NULL)
                return;         /* Ignore empty lines */
        if (builtin_command(argv))
                return;

        pid_t pid = random_fork();
        if (pid < 0) {
                perror("random_fork");
                exit(0);
        }

        /* Child runs user job */
        if (pid == 0)
                run_the_job(argv[0], argv, environ);

        /* Parent waits for foreground job to terminate */
        int ret = setpgid(pid, pid);
        if (ret < 0 && errno != EPERM && errno != EACCES)
                return;
        char buf2[MAXLINE];
        strcpy(buf2, cmdline);
        int len2 = strlen(buf2);
        buf2[len2] = '\0';
        if (!bg) {
                set_foreground(pid, buf2, len2);
                wait_for_job(pid);
        } else {
                printf("%d %s", pid, cmdline);
                pid_t ret = waitpid(pid, NULL, WNOHANG | WUNTRACED);
                if (ret == 0)
                        move_to_background(pid, JOB_RUNNING, buf2, len2);
                else if (ret == pid)
                        move_to_background(pid, JOB_STOPPED, buf2, len2);
        }
}

void stop_handler(int signo)
{
        pid_t pgid = foreground_pgid();
        char command[MAXLINE];
        get_foreground_command(command);
        int len = strlen(command) + 1;
        kill(-(int)pgid, SIGSTOP);
        if (pgid > 0)
                move_to_background(pgid, JOB_STOPPED, command, len);
        fprintf(stderr, "move job %d to background\n", pgid);
}

void interrupt_handler(int signo)
{
        pid_t pgid = foreground_pgid();
        kill(-(int)pgid, SIGINT);
}

void install_signal_handler(void)
{
        int ret;

        /* Install SIGTSTP handler */
        struct sigaction new, old;
        new.sa_handler = stop_handler;
        sigemptyset(&new.sa_mask);
        new.sa_flags = SA_RESTART;
        ret = sigaction(SIGTSTP, &new, &old);
        if (ret < 0) {
                fprintf(stderr,
                        "Warning: Failed to install SIGTSTP handler, "
                        "Leave to default handler\n");
        }

        /* Install SIGINT handler */
        memset(&new, 0, sizeof(new));
        new.sa_handler = interrupt_handler;
        sigemptyset(&new.sa_mask);
        new.sa_flags = SA_RESTART;
        ret = sigaction(SIGINT, &new, &old);
        if (ret < 0) {
                fprintf(stderr,
                        "Warning: Failed to install SIGINT handler, "
                        "Leave to default handler\n");
        }

        /* Install SIGCHLD handler */
        memset(&new, 0, sizeof(new));
        new.sa_handler = reap_child;
        sigemptyset(&new.sa_mask);
        new.sa_flags = SA_RESTART;
        ret = sigaction(SIGCHLD, &new, &old);
        if (ret < 0) {
                fprintf(stderr,
                        "Warning: Failed to install SIGCHLD handler, "
                        "Leave to default handler");
        }
}

int main(void)
{
        init_job();
        install_signal_handler();

        for (;;) {
                /* Read */
                printf("> ");
                char cmdline[MAXLINE];  /* Command line */
                char *ret = fgets(cmdline, MAXLINE, stdin);
                if (ret == NULL) {
                        if (ferror(stdin)) {
                                perror("fgets");
                                free_job();
                                return -1;
                        }
                }
                if (feof(stdin)) {
                        free_job();
                        return 0;
                }

                /* Evaluate */
                eval(cmdline);
        }
}
