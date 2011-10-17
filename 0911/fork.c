#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    pid_t pid;
    int i = 0;
    
    pid = fork();
    if(pid > 0)
    {
        while(1)
        {
            printf("I am father\n");
            sleep(1);
        }
    }
    else if(pid == 0)
    {
        while(1)
        {
            execlp("ls","ls",NULL);
        }
    }
    else
    {
        printf("fork fail\n");
        exit(-1);
    }
    return 0;
}

