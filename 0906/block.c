#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char buf[10];
    char buf1[15]="try again!";
    int fd;
    int n;
    fd = open("/dev/tty",O_RDONLY|O_NONBLOCK);
    if(fd < 0)
    {
        perror("open /dev/tty");
        exit(-1);
    }
            
tryagain: n = read(fd,buf,sizeof(buf));
            if(n < 0)
            {
                if(errno == EAGAIN)
                 {
                    sleep(1);
                    printf("2");
                     write(STDOUT_FILENO,buf1,strlen(buf1));
                    goto tryagain;
                }
                perror("open /dev/tty");
            }
            write(STDOUT_FILENO,buf,n);
            close(fd);
           return 0;
}

