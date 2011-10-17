#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
    int fd;
    int len;
    char str[10];
    fd = open("/dev/tty",O_RDWR|O_NONBLOCK);
    if(fd < 0)
    {
        perror("open fail");
        exit(-1);
    }
    try_again:
       len = read(fd,str,10); 
       if(len < 0)
       {
            if(errno == EAGAIN)
            {
               sleep(3);
               printf("try again\n");
               goto try_again;
            }
            perror("read fail");
            exit(-1);
       }
       write(fd,str,len);
    close(fd);
    return 0;
}

/*int main(int argc, const char *argv[])
{
    char buf[10];
    int n = read(STDIN_FILENO,buf,10);
    if(n < 0)
    {
        perror("read fail");
        exit(-1);
    }
    write(STDOUT_FILENO,buf,n);
    return 0;
}*/

