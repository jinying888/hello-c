#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	fd = open("./file_01.txt",O_RDWR);
	if(fd == -1){
		printf("this is error\n");
	}else{
		printf("this is normal\n");
	}
	return 0;
}
