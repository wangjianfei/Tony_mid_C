#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, const char *argv[])
{
    int fd;
    int len;
    fd = open("tttt",O_RDWR);
    if(fd < 0)
    {
        perror("open tttt fail");
        exit(-1);
    }
    len = lseek(fd,99,SEEK_SET);
    write(fd," ",1);
    printf("%d\n",len);
    close(fd);
    return 0;
}

