//屏蔽SIGQUIT信号处理，任何信号都被while里面的sigsuspend函数捕获，执行相应的信号处理函数
//只有来了SIGQUIT信号，quitflag = 1 ，才避开了sigsuspend，避免了进程挂起，
//然后再不屏蔽SIGQUIT信号处理，
//使用 ctrl + \ 产生 SIGQUTI 信号
//使用 ctrl + c 产生 SIGINT 信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int quitflag = 0;
static void sig_quit(int);
static void sig_int(int);
int main(void)
{
	sigset_t newmask, oldmask, zeromask;

	if(signal(SIGQUIT, sig_quit) == SIG_ERR){
		printf("can not catch SIGQUIT\n");
	}
	if(signal(SIGINT, sig_int) == SIG_ERR){
		printf("can not catch SIGINT\n");
	}
	
	sigemptyset(&newmask);
	sigemptyset(&oldmask);
	sigemptyset(&zeromask);
	sigaddset( &newmask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) <0){
		printf("set block that signal error\n");
	}
	sleep(5);
	

	if(sigismember(&newmask, SIGQUIT)){
		printf("\nSIGQUIT is pending\n");
	}

	sleep(2);

	while(quitflag == 0){
		printf("at while\n");
		//重新不屏蔽任何信号,SIGINT时，quitflag不变，SIGQUIT时，quitflag=1
		sigsuspend(&zeromask);
	}

	quitflag = 0;

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) <0){
		printf("set mask errot\n");
	}
	printf("unblock SIGQUIT\n");

	sleep(5);
	return 0;
}

static void sig_quit(int signo)
{
	quitflag = 1;
	printf("catch SIGQUIT\n");
	if(signal(SIGQUIT, SIG_DFL) == SIG_ERR){
		printf("can't reset SIGQUIT\n");
	}
}

static void sig_int(int signo)
{
	printf("\ninterrupt\n");
}
