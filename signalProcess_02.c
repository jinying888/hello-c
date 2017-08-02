//子进程发送给父进程发送SIGABRT信号，父进程正在要执行的语句不会执行了
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
		printf("zijinch");
		//sleep(1);
		sleep(3);
		printf("zijinch");
		printf("yyy");
	}else{
		
		printf("xxxxxxx");
		sleep(1);
		kill(pid,SIGABRT);
		printf("fujinch\n");
		for(i=0;i<10;i++){
			printf("%d",i);
		}
		sleep(2);
	}
	return 0;
}
