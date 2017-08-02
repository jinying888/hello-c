//调用vfork，在子进程中运行了exit后，才会运行父进程。
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int i = 0;
	pid_t pid;
	pid = vfork();
	if(pid ==-1){
		printf("error\n");
	}else if(pid ==0){
		i = i+10;
		exit(0);
	}else{
		i = i +1;
		printf("i=%d\n",i);
	}
	
	return 0;
}
