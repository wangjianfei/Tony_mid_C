#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include "wrap.h"    
#define SER_PORT 9090
int main(int argc, const char *argv[])
{
    int listenfd,confd;
    struct sockaddr_in sock_addr,cus_addr;
    int len;
    char buf[1024];
    listenfd = Socket(AF_INET,SOCK_STREAM,0);

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port  = htons(SER_PORT);
    sock_addr.sin_addr.s_addr =htonl(INADDR_ANY); 

    len = sizeof(sock_addr);
    bind(listenfd,(const struct sockaddr *)&sock_addr,len);

    Listen(listenfd,20);
    
    len = sizeof(cus_addr);
    confd = Accept(listenfd,(struct sockaddr *)&cus_addr,&len);

    while(1)
    {
        len = Read(confd,buf,sizeof(buf));
        Write(STDOUT_FILENO,buf,len);
        Write(STDOUT_FILENO,"\n",1);
        printf("please input\n");
        len = Read(STDIN_FILENO,buf,sizeof(buf));
        Write(confd,buf,len);
    }
    close(listenfd);
    close(confd);
    return 0;
}

