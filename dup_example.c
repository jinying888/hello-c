//文件描述符重定向
//创建无名管道,f_des[0]是读端，f_des[1]是写端，dup2复制文件描述符到第二个
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int f_des[2];
	if(-1 == pipe(f_des)){

		printf("create pipe\n");
		exit(-1);
	}
	
	pid_t pid;

	pid = fork();

	if(pid == -1){
		printf("fork error\n");
	}else if(pid == 0){
		dup2(f_des[0],0);
		close(f_des[1]);//关闭写端，不然execlp会阻塞
		//char buf[128];
		execlp("sort", "sort", (char *)0);
	}else{
		pid = fork();
		if(pid == -1){
			printf("fork error\n");
		}else if(pid == 0){
			dup2(f_des[1],1);
			close(f_des[0]);
			execlp("who","who",(char *)0);
		}else{
			close(f_des[0]);
			close(f_des[1]);
			wait(NULL);
			wait(NULL);
		}
	}

	return 0;
}
