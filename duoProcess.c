#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
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
		i= i+2;
	}

	printf("pid = %ld,i = %d,j = %d\n",(long)getpid(), i, j);
	exit(0);
}
