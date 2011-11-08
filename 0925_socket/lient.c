#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <strings.h>

#define  SOCK_PORT 4869 

int main(int argc, const char *argv[])
{
    struct sockaddr_in clen_addr;
    int clenfd;
    int len;
    char buf[] = "wang jian fei !";
    clenfd = socket(AF_INET,SOCK_STREAM,0);
    /*传参不正确 内存不够*/
    bzero(&clen_addr, sizeof(clen_addr));
    clen_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &clen_addr.sin_addr);
    clen_addr.sin_port = htons(SOCK_PORT);

    len = sizeof(clen_addr);

    connect(clenfd,(struct sockaddr *)&clen_addr,len);
    int i = 10;
    while(1)
    {
    write(clenfd,buf,sizeof(buf));
    sleep(1);
    }
    close(clenfd);
    
    return 0;
}


