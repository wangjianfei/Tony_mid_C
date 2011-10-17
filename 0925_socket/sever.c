#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <strings.h>
#include <netinet/in.h>

#define SOCK_PORT 9090


int main(int argc, const char *argv[])
{
    int listenfd,confd;
    int len = 0;
    char buf[1024];
    struct sockaddr_in sock_addr,con_addr;

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(SOCK_PORT);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = socket(AF_INET,SOCK_STREAM,0);
    len = sizeof(sock_addr);
    bind(listenfd,(struct sockaddr *)&sock_addr,len);
    listen(listenfd,20);
    len = sizeof(con_addr);
    confd = accept(listenfd,(struct sockaddr *)&con_addr,&len);

    len = read(confd,buf,sizeof(buf));
    write(STDOUT_FILENO,buf,len);

    close(listenfd);
    close(confd);

    return 0;
}

