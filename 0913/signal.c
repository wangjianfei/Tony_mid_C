#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sighandler(int num)
{
    printf("wangjianfei\n");
}

int main(int argc, const char *argv[])
{
    struct sigaction sig_set;
    struct sigaction sigset;
    sigemptyset(&sig_set.sa_mask);
    sigfillset(&sig_set.sa_mask);
    sig_set.sa_handler = sighandler;
    sig_set.sa_flags = 0;
/*    sigemptyset(&sigset.sa_mask);
    sigfillset(&sigset.sa_mask);
    sigset.sa_handler = sighandler;
*/
    sigaction(2,&sig_set,NULL);
    
  //  sigaction(3,&sigset,NULL);
    while(1)
    {
        printf("akaedu\n");
        sleep(1);
    }
    return 0;
}

