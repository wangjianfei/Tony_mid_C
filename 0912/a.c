#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void handler(int num)
{
    printf("stop\n");
}

int main(int argc, const char *argv[])
{
    int fd;
    struct sigaction sig_set;
    char str[100]="wang jian fei";
    sig_set.sa_handler = handler;
    sigemptyset(&sig_set.sa_mask);
    sigfillset(&sig_set.sa_mask);
    sig_set.sa_flags = 0;
    sigaction(13,&sig_set,NULL);

    fd = open("pipofifo",O_WRONLY);
    if(fd < 0)
    {
        perror("open pipofifo");
        exit(-1);
    }
    while(1)
    {
       write(fd,str,strlen(str)); 
       sleep(1);
    }

    return 0;
}

