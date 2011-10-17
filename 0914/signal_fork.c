#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

void sighandler(int num)
{
    pid_t pid;
    while(1)
    {
         pid = waitpid(-1,NULL,WNOHANG); 
         if(pid == -1)
         {
            break;
         }
    }
}

int main(int argc, const char *argv[])
{
    pid_t pid1,pid2,pid3,pid4;
    int i = 0;
    struct sigaction sig_set;
    pid1 = fork();
    if(pid1 > 0)
    {
        pid2 = fork();
        if(pid2 > 0)
        {
             pid3 = fork();
             if(pid3 > 0)
             {
                pid4 = fork();
                if(pid4 > 0)
                {
                    sig_set.sa_handler = sighandler;
                    sigemptyset(&sig_set.sa_mask);
                    sigfillset(&sig_set.sa_mask);
                    sig_set.sa_flags = 0;
                    sigaction(17,&sig_set,NULL);
                    while(1)
                    {
                         printf("I am parent111111111\n");
                         sleep(1);
                    }
                }
                else if( pid4 == 0)
                {
                    for(i = 0;i < 20;i++)
                    {
                        printf("I am child4\n");
                        sleep(1);
                    }
                }
             }
             else if(pid3 == 0)
             {
                for(i = 0;i< 15;i++)
                {
                     printf("I am child3\n");
                     sleep(1);
                }
             }
             else
             {
                 perror("pid3 fail");
                 exit(-1);
             }
        }
        else if(pid2 == 0)
        {
           // kill(getppid,2);
           for(i = 0;i < 10;i++)
           {
                printf("I am child2\n");
                sleep(1);
           }
        }
        else
        {
            perror("pid2 fail");
            exit(-1);
        }

    }
    else if( pid1 == 0)
    {
       for(i = 0;i < 5;i++)
       {
            printf("I am child1\n");
            sleep(1);
       }
      // kill(getppid,2);
      // abort();
    }
    else
    {
        perror("pid1 fail");
        exit(-1);
    }
    return 0;
}

