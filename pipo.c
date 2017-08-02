#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid, child, child2;
    int status;
    printf("haha");

if(pid = fork() == -1){
    printf("fokr error");
    exit(1);
}else if(pid == 0){
    printf("i am child\n");
}else if(pid > 0){
    printf("i am main\n");
}

    printf("eee\n");

}
