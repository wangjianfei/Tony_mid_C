#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	int res=0, i = 10;
	sigset_t set, oldset, spend;
	sigemptyset(&set);
	sigemptyset(&spend);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_SETMASK, &set, &oldset);
	while (1) {
		sigpending(&spend);
		res = sigismember(&spend, SIGINT);
		printf("hhhh\n");
		printf("SIGINTPENDING is %d\n", res);
		i--;
		sleep(1);
		if (i == 0) {
			sigprocmask(SIG_SETMASK, &oldset, NULL);
		}
	}
    return 0;
}
