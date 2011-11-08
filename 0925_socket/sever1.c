#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include "wrap.h"    
#define SER_PORT 4869 
int main(int argc, const char *argv[])
{
    int listenfd,confd;
    struct sockaddr_in sock_addr,cus_addr;
    int len;
    char buf[1024];
    listenfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port  = htons(SER_PORT);
    sock_addr.sin_addr.s_addr =htonl(INADDR_ANY); 

    len = sizeof(sock_addr);
    bind(listenfd,(const struct sockaddr *)&sock_addr,len);

    listen(listenfd,20);
    
    len = sizeof(cus_addr);
    confd = accept(listenfd,(struct sockaddr *)&cus_addr,&len);

    while(1)
    {
        len = read(confd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
        write(STDOUT_FILENO,"\n",1);
        printf("please input\n");
        len = read(STDIN_FILENO,buf,sizeof(buf));
        write(confd,buf,len);
    }
    close(listenfd);
    close(confd);
    return 0;
}

