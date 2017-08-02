#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
    int i;
    pid_t pid;

    for(i=0;i<2;i++){
    
    pid = fork();
    
    if(pid == -1){
        printf("error\n");
    }else if(pid == 0){
        printf("in the child\n");
    }
    printf("xxxx\n");

    }

    return 0;
}
