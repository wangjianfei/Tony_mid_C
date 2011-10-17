#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "wrap.h"
#define SER_PORT 9090

int main(int argc, const char *argv[])
{
    int listenfd,confd;
    int len;
    int fd[2];
    int f_d[2];
    pid_t pid;
    struct sockaddr_in sock_addr,con_addr;
    char buf[1024];
    listenfd = Socket(AF_INET,SOCK_STREAM,0);

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(SER_PORT);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(sock_addr);
    Bind(listenfd,(const struct sockaddr *)&sock_addr,len);
    
    Listen(listenfd,20);
    if(pipe(fd) != 0)
    {
        perror("pipe fail");
        exit(1);
    }
    if(pipe(f_d) != 0)
    {
        peror("pipe fail");
        exit(1);
    }
    pid = fork();
    if(pid > 0)
    {
        while(1)
        {
             len = sizeof(con_addr);
             confd = accept(listenfd,(struct sockaddr *)&con_addr,&len);
             pid = fork();
             if(pid < 0)
             {
                perror("fork error");
                exit(1);
             }
             if(pid == 0)
             {
                Close(listenfd);
                Close(fd[0]);

                while(1)
                {
                    len = Read(confd,buf,sizeof(buf));
                    Write(fd,buf,len);
                    
                }
                Close(confd);
                exit(1);
             }
             else
             {
                Close(confd);
             }
    }
    else if(pid == 0)
    {
        while((len = Read(fd,buf,sizeof(buf)))>0)
        {
            if(buf[0] == "a")
            {
                
            }
        }
    }
    else
    {
        perror("fork1 fail");
        exit(1);
    }
    return 0;
}
















