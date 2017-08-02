//屏蔽SIGQUIT信号处理，然后再不屏蔽SIGQUIT信号处理
//使用 ctrl + \ 产生 SIGQUTI 信号
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_quit(int);

Sigfunc *signal(int, Sigfunc *);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;
	if(signal(SIGQUIT, sig_quit) == SIG_ERR){
		printf("can not catch SIGQUIT\n");
	}
	
	sigemptyset(&newmask);
	sigemptyset(&oldmask);
	sigemptyset(&pendmask);
	sigaddset( &newmask, SIGQUIT);
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) <0){
		printf("set block that signal error\n");
	}
	sleep(5);
	
	if(sigpending(&pendmask) <0){
		printf("get pending signal error");
	}

	if(sigismember(&pendmask, SIGQUIT)){
		printf("\nSIGQUIT is pending\n");
	}

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) <0){
		printf("set mask errot\n");
	}
	printf("unblock SIGQUIT\n");

	sleep(5);
	return 0;
}

static void sig_quit(int signo)
{
	printf("catch SIGQUIT\n");
	if(signal(SIGQUIT, SIG_DFL) == SIG_ERR){
		printf("can't reset SIGQUIT\n");
	}
}

Sigfunc *signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	
	if(sigaction(signo, &act, &oact) < 0){
		return(SIG_ERR);
	}
	return(oact.sa_handler);
}
