#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd;
    char str[4096];
    int len = 0;
    fd = open("pipofifo",O_RDONLY);
    if(fd < 0)
    {
        perror("open pipofifo");
        exit(-1);
    }
    while(1)
    {
        len = read(fd,str,sizeof(str));
        write(STDOUT_FILENO,str,len);
//        write(STDOUT_FILENO,"\n",1);
        sleep(1);
    }
    return 0;
}


