#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define SOCK_PORT 9090

int main(int argc, const char *argv[])
{
    int fd,n;
    int len = 0;
    char buf[1024];
    struct sockaddr_in sock_addr;

    fd = socket(AF_INET,SOCK_DGRAM,0 );

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(SOCK_PORT);
    inet_pton(AF_INET,"127.0.0.1",&sock_addr.sin_addr);

    while(1)
    {
        len = read(STDIN_FILENO,buf,sizeof(buf));
        n  = sendto(fd,buf,len,0,(const struct sockaddr *)&sock_addr,sizeof(sock_addr));
        if(n == -1)
        {
            perror("sendto fail");
        }
        n = recvfrom(fd,buf,1024,0,NULL,0);
        if(n == -1)
        {
            perror("recvfrom fail");
        }
        write(STDOUT_FILENO,buf,n);
    }
        close(fd);

    return 0;
}

