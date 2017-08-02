#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	fd = open("./cfile/file_01.txt",O_RDWR | O_CREAT | O_EXCL);
	if(fd == -1){
		printf("this is error\n");
	}else{
		printf("this is normal\n");
	}
	return 0;
}
