#include <stdio.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "wrap.h"
#include <stdlib.h>
#include <netinet/in.h>
#include <strings.h>


#define SOCK_PORT 9090
int main(int argc, const char *argv[])
{
    int sockfd;
    int n =0;
    int i = 0;
    char buf[1024]; 
    char str[1024];
    socklen_t conaddr_len;
    struct sockaddr_in sock_addr,con_addr;
    sockfd = Socket(AF_INET,SOCK_DGRAM,0);

    bzero(&sock_addr,sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(SOCK_PORT);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(sockfd,(const struct sockaddr *)&sock_addr,sizeof(sock_addr));
    
    while(1)
    {
        conaddr_len  = sizeof(con_addr);
        n = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&con_addr,&conaddr_len);
        if(n < 0)
        {
            perror("recvfrom fail");
        }

        printf("conaddr IP %s   port %d\n",inet_ntop(AF_INET,&con_addr.sin_addr,str,sizeof(str)),ntohs(con_addr.sin_port));
        for(i = 0;i < n;i++)
        {
            buf[i] = toupper(buf[i]); 
        }
        
        n = sendto(sockfd,buf,n,0,(struct sockaddr *)&con_addr,sizeof(con_addr));
        if(n == -1)
        {
            perror("sendto fail");
        }
    }
    return 0;
}

