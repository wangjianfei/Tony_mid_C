#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>

int flag = 0;

void sighandler(int num)
{
    pid_t number =0;
    while(1)
    {
        number = waitpid(-1,NULL,WNOHANG); 
        if(number > 0)
        {
            flag++;
        }
        if(number == 0)
        {
            break;
        }
        if(number < 0)
        {
            break;
        }
        printf("%d\n",flag);
    }
} 
int main(int argc, const char *argv[])
{
    int myint;
    struct stat mystat;
    struct sigaction sig_set;
    char *p = NULL;
    char *p1 = NULL;
    char *pr = NULL;
    int fd;
    int fd1;
    fd = open("signal",O_RDWR);
    if(fd < 0)
    {
        perror("open signal fail");
        exit(-1);
    }
    //myint = fstat(fd,&mystat);
    fstat(fd,&mystat);
    if(myint < 0)
    {
        perror("fstat fail");
        exit(-1);
    }
    p = mmap(NULL,mystat.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
    {
        perror("mmap 111");
        exit(-1);
    }
//    close(fd);
    fd1 = open("tttt",O_RDWR|O_CREAT,0777);
    if(fd1 < 0)
    {
        perror("open tttt fail");
        exit(-1);
    }
    lseek(fd1,mystat.st_size-1,SEEK_SET);
    write(fd1," ",1);
    p1 = mmap(NULL,mystat.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd1,0);

    if(p1 == MAP_FAILED)
    {
        perror("mmap 22");
        exit(-1);
    }
//    close(fd1);
    pid_t pid1,pid2,pid3;
    pid1 = fork();
    if(pid1 > 0)
    {
        pid2 = fork();
        if(pid2 > 0)
        {
            pid3 = fork();
            if(pid3 > 0)
            {
                    sigemptyset(&sig_set.sa_mask);
                    sigfillset(&sig_set.sa_mask);
                    sig_set.sa_flags = 0;
                    sig_set.sa_handler = sighandler;
                    sigaction(17,&sig_set,NULL);
                while(1)
                {
                    if(flag == 3)
                    {
                        printf("copy complete\n");
                        exit(-1);
                    }
               }
            }
            else if(pid3 == 0)
            {
            pr = p;    
            p = p+2*mystat.st_size/3;
            
            p1 = p1+2*mystat.st_size/3;
            while(p != (pr+mystat.st_size))
            {
                *p1 = *p;
                p1++;
                p++;
                usleep(20000); 
            }
            }
        }
        else if(pid2 == 0)
        {
            p = p+mystat.st_size/3;
            pr = p;
            p1 = p1+mystat.st_size/3;
            while(p != (pr+mystat.st_size/3))
            {
                *p1 = *p;
                p1++;
                p++;
                usleep(10000);
            }
        }
        else
        {
            perror("pid2 fail");
            exit(-1);
        }
    }
    else if(pid1 == 0)
    {
             pr = p;
        while(p != (pr+mystat.st_size/3))
        {
             *p1 = *p;
             p1++;
             p++;
             usleep(30000);
        }
    }
    else
    {
        perror("pid1 fail");
        exit(-1);
    }
    return 0;
}

