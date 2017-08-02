//子进程发送给自己一个SIGABRT信号，子进程后续语句不会执行了
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main()
{
	int i = 0;
	pid_t pid;
	pid = fork();
	if(pid == -1){
		printf("fork error\n");
	}else if(pid == 0){
		kill(getpid(),SIGABRT);
		printf("zijinch");
	}else{
		printf("fujinch\n");
	}
	return 0;
}
