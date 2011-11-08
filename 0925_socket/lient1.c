#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include "wrap.h"
#define SOCK_PORT 4869 

int main(int argc, const char *argv[])
{
    int fd;
    struct sockaddr_in sock_addr;
    int len;
    char buf[1024];
    fd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(SOCK_PORT);
    inet_pton(AF_INET, "127.0.0.1", &sock_addr.sin_addr);
    len = sizeof(sock_addr);
    connect(fd,(const struct sockaddr *)&sock_addr,len);

    while(1)
    {
        printf("please input:\n");
        len=  read(STDIN_FILENO,buf,sizeof(buf));
        write(fd,buf,len);
        len = read(fd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
        write(STDOUT_FILENO,"\0",1);


    }
    Close(fd);
    return 0;
}

