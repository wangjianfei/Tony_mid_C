#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd[2],len = 0;
    int fd2[2],len1 = 0;
    pid_t pid;
    int fd1;
    char str[4096]= "wang";
    char str1[4096]= "jianfei";
    if(pipe(fd) != 0)
    {
        perror("pipe fail");
        exit(-1);
    }
    if(pipe(fd2) != 0)
    {
        perror("pipe fail");
        exit(-1);
    }
    pid = fork();
    if(pid == 0)
    {
        close(fd[0]);
        close(fd2[1]);
        while(1)
        {
        len1 = read(fd2[0],str1,sizeof(str1));
        write(STDOUT_FILENO,str1,len1);
        write(STDOUT_FILENO,"\n",1);
        write(fd[1],str,strlen(str));
        sleep(3);
        }
    }
    else if(pid > 0)
    {
    while(1)
    {
        close(fd[1]);
        close(fd2[0]);
        write(fd2[1],str1,strlen(str1));
        len = read(fd[0],str,sizeof(str));
        write(fd1,str,len);
        write(STDOUT_FILENO,"\n",1);
        sleep(3);
      //  wait(NULL);
    }
    }
    return 0;
}

