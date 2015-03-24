

/*
 * 重定向：将文件的输入流作为主进程fstatcheck的标准输入
*/

int main(){
	

	if (Fork() == 0) { /* Child */
    	/* The Shell may be run these code? */
    	fd = Open("foo.txt", O_RDONLY, 0); /* fd == 3 */
    	Dup2(fd, STDIN_FILENO);
    	Close(fd);
    	Execve("fstatcheck", argv, envp);
	}

}
