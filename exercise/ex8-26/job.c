/*
 * 8.26
 *
 * mofaph@gmail.com
 * 2013-7-14
 *
 * 这个文件包含了用来处理作业控制的代码
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "job.h"

/*
 * 作业控制列表从 1 开始计数，第 0 个位置是前台进程组
 */

static const int beg = 1;
static int max, end;
static struct job **job;

/* empty: 1, otherwise: 0 */
int is_empty(struct job *job_list[], int len)
{
        int i;
        for (i = beg; i < len; i++) {
                if (job_list[i])
                        return 0;
        }
        return 1;
}

void init_job(void)
{
        /* Background */
        max = 2;
        end = 1;
        job = malloc(sizeof(struct job *) * max);
        if (!job) {
                fprintf(stderr, "init_job: malloc error\n");
                exit(-1);
        }

        /* Foreground */
        job[0] = malloc(sizeof(struct job));
        if (!job[0]) {
                fprintf(stderr, "init_job: init foreground process failed!\n");
                free_job();
                exit(-1);
        }
        job[0]->command = NULL;
}

void free_job(void)
{
        int i;
        for (i = 0; i < end; i++)
                free(job[i]);
        free(job);
}

int add_job(pid_t pgid, int state, char *command, int len)
{
        struct job *j = malloc(sizeof(struct job));
        if (!j)
                goto malloc_failed;
        j->pgid = pgid;
        j->state = state;
        j->command = malloc(len);
        if (!j->command)
                goto malloc_failed;
        memmove(j->command, command, len);

        if (end != beg && is_empty(job, end))
                end = beg;
        if (end+1 == max) {
                struct job **old_job = job;
                int new_max = max * 3 / 2;
                job = realloc(old_job, new_max*sizeof(struct job *));
                if (!job) {
                        job = old_job;
                        free(j->command);
                        goto malloc_failed;
                }
                max = new_max;
        }
        job[end] = j;
        end += 1;
        printf("add_job: job list %d long now\n", end);

        return 0;

malloc_failed:
        perror("malloc");
        fprintf(stderr, "add_job: malloc failed!\n");
        free(j);                /* 释放 NULL 是无害的 */
        return -1;
}

int find_job(pid_t pgid)
{
        int i;
        for (i = beg; i < end; i++)
                if (job[i] && job[i]->pgid == pgid)
                        return i;
        return -1;
}

void delete_job(pid_t pgid)
{
        int jid = find_job(pgid);
        if (jid >= beg) {
                free(job[jid]);
                job[jid] = NULL;
        }
}

void update_job(pid_t pgid, int state)
{
        int jid = find_job(pgid);
        if (beg <= jid && jid < end) {
                job[jid]->state = state;
                printf("[%d] %d %s\n", jid, (int)pgid, job[jid]->command);
        } else {
                printf("%d: No such process\n", (int)pgid);
        }
}

pid_t get_pgid(int jid)
{
        if (jid < end && job[jid])
                return job[jid]->pgid;
        return -1;
}

void print_job(int i)
{
        printf("[%d] %d", i, (int)job[i]->pgid);
        char *job_state;
        if (job[i]->state == JOB_RUNNING)
                job_state = "Running";
        else if (job[i]->state == JOB_STOPPED)
                job_state = "Stopped";
        else if (job[i]->state == JOB_DONE)
                job_state = "Done";
        else
                job_state = "Unkown";
        printf(" %s %s\n", job_state, job[i]->command);
}

void print_job_by_pgid(pid_t pgid)
{
        int jid = find_job(pgid);
        print_job(jid);
}

void print_all_job(void)
{
        int i;
        for (i = beg; i < end; i++) {
                if (!job[i])
                        continue;
                print_job(i);
                if (job[i]->state == JOB_DONE)
                        delete_job(job[i]->pgid);
        }
}

void print_foreground(void)
{
        if (job[0]->command)
                printf("%s\n", job[0]->command);
}

void set_foreground(pid_t pgid, char *command, int len)
{
        job[0]->pgid = pgid;
        job[0]->state = JOB_RUNNING;
        job[0]->command = malloc(len);
        if (!job[0]->command) {
                perror("malloc");
                exit(-1);
        }
        memmove(job[0]->command, command, len);
}

pid_t foreground_pgid(void)
{
        return job[0]->pgid;
}

void get_foreground_command(char *command)
{
        int len = strlen(job[0]->command) + 1;
        memmove(command, job[0]->command, len);
}

void move_to_background(pid_t pgid, int state, char *command, int len)
{
        int jid = find_job(pgid);
        if (jid < 0)
                add_job(pgid, state, command, len);
        else
                update_job(pgid, state);
}

void move_to_foreground(pid_t pgid)
{
        int jid = find_job(pgid);
        if (jid >= beg)
                *job[0] = *job[jid];
        else
                printf("%d: No such process\n", (int)pgid);
}
