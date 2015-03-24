/*
 * 8.26
 *
 * mofaph@gmail.com
 * 2013-7-14
 */

#ifndef __job_h
#define __job_h

#include <unistd.h>

#define JOB_RUNNING 0
#define JOB_STOPPED 1
#define JOB_DONE    2

struct job {
        pid_t pgid;             /* 进程组 ID */
        int state;              /* 作业状态 */
        char *command;          /* 运行作业的命令 */
};

extern void init_job(void);
extern int add_job(pid_t pgid, int state, char *command, int len);
extern void delete_job(pid_t pgid);
extern int find_job(pid_t pgid);
extern void free_job(void);
extern void update_job(pid_t pgid, int state);

extern pid_t get_pgid(int jid);

extern void print_job(int i);
extern void print_job_by_pgid(pid_t pgid);
extern void print_all_job(void);

extern pid_t foreground_pgid(void);
extern void get_foreground_command(char *command);
extern void print_foreground(void);
extern void set_foreground(pid_t pgid, char *command, int len);
extern void move_to_background(pid_t pgid, int state, char *command, int len);
extern void move_to_foreground(pid_t pgid);

#endif  /* __job_h */
