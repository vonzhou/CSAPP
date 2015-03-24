/*
 * p519 -- code/ecf/procmask1.c
 *
 * 一个具有细微同步错误的外壳程序。如果子进程在父进程能够开始运行前就结束了，那么
 * addjob() 和 deletejob() 会以错误的方式被调用
 *
 * 这个程序希望父进程在一个作业列表中记录着它的当前子进程，每个作业条目。
 * addjob() 和 deletejob() 分别想这个作业列表添加和从中删除作业。
 *
 * 当父进程创建一个新的子进程时，它就把这个子进程添加到作业列表中。当父进程在
 * SIGCHLD 处理程序中回收一个终止的（僵死）子进程时，它就从作业列表中删除这个子进
 * 程。乍一看，这段代码是对的。不幸的是，可能发生下面的情况：
 *
 * 1. 父进程执行 fork()，内核调度新创建的子进程运行，而不是父进程
 *
 * 2. 在父进程能够再次运行之前，子进程就终止，并且变成一个僵死进程，使得内核传递
 *    一个 SIGCHLD 信号给父进程
 *
 * 3. 后来，当父进程再次变成可运行但又在它执行之前，内核注意到待处理的 SIGCHLD 信
 *    号，并通过在父进程中运行处理程序接收这个信号
 *
 * 4. 处理程序回收终止的子进程，并调用 deletejob()，这个函数什么都不做，因为父进
 *    程还没有把该子进程添加到列表中
 *
 * 5. 在处理程序运行结束后，内核运行父进程，父进程从 fork() 返回，通过调用
 *    addjob() 错误地把（不存在的）子进程添加到作业列表中
 *
 * 因此，对于父进程的 main 函数流和信号处理流的某些交错，可能会在 addjob() 之前调
 * 用 deletejob()。这导致作业列表中出现一个不正确的条目，对应于一个不再存在而且永
 * 远不会被删除的作业。另一方面，也有一些交错，事件按照正确的顺序发生。例如，如果
 * 在 fork() 调用返回时，内核刚好调度父进程而不是子进程运行，那么父进程就会正确地
 * 把子进程添加到作业列表中，然后子进程终止，信号处理函数把该作业从列表中删除。
 *
 * 这是一个称为竞争（race）的经典同步错误的示例。在这种情况下，main() 中调用
 * addjob() 和处理程序中调用 deletejob() 之间存在竞争。如果 addjob() 赢得进展，那
 * 么结果就是正确的。如果它没有，那么结果就是错误的。这样的错误非常难以调试，因为
 * 几乎不可能测试所有的交错。你可能运行这段代码十亿次，也没有一次错误，但是下一次
 * 测试却导致引发竞争的交错。
 */

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
        initjobs();             /* Initialize the job list */

        while (1) {
                /* Child process */
                if ((pid = Fork()) == 0) {
                        Execve("/bin/date", argv, NULL);
                }

                /* Parent process */
                addjob(pid);    /* Add the child to the job list */
        }

        exit(0);
}
