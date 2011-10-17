#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int srcfb,destfb;
    char buf[4096];
    int len;
    srcfb = open(argv[1],O_RDONLY);
    if(srcfb < 0)
    {
        perror("open srcfb");
        exit(-1);
    }
    destfb = open(argv[2],O_RDWR|O_CREAT|O_EXCL,0777);
    if(destfb < 0)
    {
        perror("open destfb");
        exit(-1);
    }
    while(len = read(srcfb,buf,sizeof(buf)))
    {
        write(destfb,buf,len);
    }
    close(destfb);
    close(srcfb);
    return 0;
}

