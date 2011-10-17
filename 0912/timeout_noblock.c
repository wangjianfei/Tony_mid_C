#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
    int fd = 0;
    int i = 0;
    int len =0;
    char str[10];
    fd = open("/dev/tty",O_RDWR|O_NONBLOCK);
    if(fd < 0)
    {
        perror("open /dev/tty");
        exit(-1);
    }
    for(i = 0 ;i < 5;i++) 
    {
        len = read(fd,str,10);
        if(len > 0)
        {
            break;
        }
        if(errno != EAGAIN)
        {
            perror("errno fail");
            exit(-1);
        }
        printf("tryagain\n");
        sleep(3);
    }
    if(i == 5)
    {
        printf("timeout\n");
    }
    else
    {
        write(fd,str,len);
    }
    close(fd);
    return 0;
}

