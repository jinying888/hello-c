//有名管道的写端，写入管道，当读端还没有存在时，阻塞
//有名管道在打开时，对方不存在，阻塞
//无名管道在读写时，对方不存在，阻塞
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myfifo"

int main()
{
	int fifo_fd;
	int res;
	char buffer[] = "hello,world!";
	//判断文件是否存在
	if(access(FIFO_NAME, F_OK) == -1){
		res = mkfifo(FIFO_NAME, 0766);
		if(res != 0){
			fprintf(stderr,"can not create fifo %s\n", FIFO_NAME);
			exit(-1);
		}
	}

	printf("Process %d opening FIFO O_WRONLY\n", getpid());
	fifo_fd = open(FIFO_NAME, O_WRONLY);
	printf("the file descriptor is %d\n", fifo_fd);
	if(fifo_fd != -1){
		res = write(fifo_fd,buffer,sizeof(buffer));
		if(res == -1){
			fprintf(stderr, "write error on fif\n");
			exit(-1);
		}
		printf("wrote data is %s,%d bytes is write\n", buffer, res);
		close(fifo_fd);	

	}else{
		exit(-1);
	}
	
	printf("Process %d finished\n", getpid());
	return 0;
}
