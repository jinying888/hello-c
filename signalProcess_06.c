//屏蔽SIGINT信号处理，然后使用sigsuspend函数屏蔽SIGUSAER1信号处理,
//进程挂起，收到信号后，恢复之前的屏蔽mask，继续屏蔽SIGINT信号
//使用 ctrl + \ 产生 SIGQUTI 信号
//使用 ctrl + c 产生 SIGINT 信号
//SIG_DFL 默认处理信号
//SIG_IGN 忽略信号

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_int(int);

int main(void)
{
	sigset_t newmask, oldmask, waitmask;
	if(signal(SIGINT, sig_int) == SIG_ERR){
		printf("can not catch SIGINT\n");
	}
	
	sigemptyset(&newmask);
	sigemptyset(&oldmask);
	sigemptyset(&waitmask);
	sigaddset( &newmask, SIGINT);
	sigaddset( &waitmask, SIGUSR1);
	
	sleep(5);
	
	//block SIGINT
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) <0){
		printf("set block that signal error\n");
	}

	//critical region
	//do sthing
	printf("this is region code\n");

	sleep(5);
	//pause , allowing all signals except SIGUSER1
	if(sigsuspend(&waitmask) != -1){
		printf("sigsuspend error\n");
	}

	exit(0);

}

static void sig_int(int signo)
{
	printf("catch SIGINT\n");
}
