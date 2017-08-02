#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

void handler(int sig)
{
	printf("sig=%d\n",sig);
}


int main()
{
	int j;
	signal(SIGPIPE,handler);
	unlink("FIFO");
	//创建有名管道
	mkfifo("FIFO",0644);
	
	pid_t pid;

	pid = fork();
	if(pid == -1){
		printf("fork error");
	}else if(pid ==0){
		int fd;
		//已只读方式打开管道
		fd = open("FIFO",O_RDONLY);
		close(fd);
	}else{
		int fd;
		fd = open("FIFO",O_WRONLY);
		int ret;
		sleep(2);
		ret = write(fd,"hello,world!",12);
		printf("ret=%d\n", ret);
	}
}

