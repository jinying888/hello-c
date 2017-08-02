//父进程等待，子进程产生alarm，并且自己捕捉
//pause可以使进程挂起，然后等待信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void func_alarm(int signo)
{
	printf("catch alarm\n");
}

int main()
{
	int status;
	int i;
	int j;
	i = j = 0;
	pid_t pid;
	pid = fork();
	if(pid == -1){
		printf("fork error\n");
	}else if(pid == 0){
		j= j+1;
		signal(SIGALRM,func_alarm);
		alarm(2);
		pause();
	}else{
		waitpid(pid,&status,0);
		//printf("zijincheng:%d\n",status);
		i= i+2;
	}

	printf("pid = %ld,i = %d,j = %d\n",(long)getpid(), i, j);
	exit(0);
}
