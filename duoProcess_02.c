#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
	}else{
		waitpid(pid,&status,0);
		//printf("zijincheng:%d\n",status);
		i= i+2;
	}

	printf("pid = %ld,i = %d,j = %d\n",(long)getpid(), i, j);
	exit(0);
}
