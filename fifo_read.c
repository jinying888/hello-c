//有名管道打开，并且读取数据
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
	char buffer[4096];
	int bytes_read = 0;
	//buffer用\0填充
	memset(buffer,'\0', sizeof(buffer));
	printf("Process %d opening FIFO O_RDONLY\n", getpid());

	fifo_fd = open(FIFO_NAME, O_RDONLY);
	printf("the file descriptor is %d\n", fifo_fd);
	if(fifo_fd != -1){
		bytes_read = read(fifo_fd, buffer, sizeof(buffer));
		if(bytes_read != -1){
			printf("the read data is %s\n", buffer);
		}else{
			exit(-1);
		}
		close(fifo_fd);
	}else{

		exit(-1);
	}
	
	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	return 0;
}
