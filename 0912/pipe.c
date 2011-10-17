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
  //  int fd2[2];
    pid_t pid;
    int fd1;
    int i = 0;
    char str[4096];
    if(pipe(fd) != 0)
    {
        perror("pipe fail");
        exit(-1);
    }
  /*  if(pipe(fd2) != 0)
    {
        perror("pipe fail");
        exit(-1);
    }*/
    pid = fork();
    if(pid == 0)
    {
        close(fd[0]);
       // close(fd2[2]);
        while(i < 3)
        {
            printf("please input\n");
            fgets(str,100,stdin);
            write(fd[1],str,strlen(str));
            i++;
            sleep(1);
        }
    }
    else if(pid > 0)
    {
        close(fd[1]);
        fd1 = open("tttt",O_RDWR|O_CREAT|O_APPEND,0777);
        if(fd < 0)
        {
            perror("open");
            exit(-1);
        }
        while(i < 3)
        {
        len = read(fd[0],str,sizeof(str));
        write(fd1,str,len);
      //  write(STDOUT_FILENO,"\n",1);
        i++;
        sleep(1);
        }
        wait(NULL);
    }
    return 0;
}

