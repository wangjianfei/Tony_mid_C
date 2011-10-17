#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include "wrap.h"
#define SOCK_PORT 9090

int main(int argc, const char *argv[])
{
    int fd;
    struct sockaddr_in sock_addr;
    int len;
    char buf[1024];
    fd = Socket(AF_INET,SOCK_STREAM,0);

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(SOCK_PORT);
    inet_pton(AF_INET, "192.168.1.22", &sock_addr.sin_addr);
    len = sizeof(sock_addr);
    Connect(fd,(const struct sockaddr *)&sock_addr,len);

    while(1)
    {
        printf("please input:\n");
        len=  Read(STDIN_FILENO,buf,sizeof(buf));
        Write(fd,buf,len);
        len = Read(fd,buf,sizeof(buf));
        Write(STDOUT_FILENO,buf,len);
        Write(STDOUT_FILENO,"\0",1);


    }
    Close(fd);
    return 0;
}

