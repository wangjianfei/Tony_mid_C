#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int srcfd,destfd;
    char buf[4096];
    int len;
    srcfd = open(argv[1],O_RDONLY);
    if(srcfd < 0)
    {
        perror("open srcfd");
        exit(-1);

    }
   destfd = open(argv[2],O_RDWR|O_CREAT|O_EXCL,0777);
   if(destfd < 0)
   {
        perror("open destfd");
        exit(-1);
   }
   while((len = read(srcfd,buf,sizeof(buf))))
   {
        write(destfd,buf,len);
   }
   close(srcfd);
   close(destfd);
    return 0;
}

