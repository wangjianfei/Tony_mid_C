#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fd;
    int *p;
    char str[4096];
    int i = 0;
    int len= 0;
    fd = open("tttt",O_RDWR);
    if(fd < 0)
    {
        perror("open tttt fail");
        exit(-1);
    }
    p = mmap(NULL,4096,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
    {
        perror("mmap");
        exit(-1);
    }
    close(fd);
    while(i < 100)
    {
        printf("%c\n",*p);
        i++;
        p++;
        sleep(2);
    }
    return 0;

}
