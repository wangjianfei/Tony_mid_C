#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int fd;
    fd = open("tttt",O_RDWR);
    if(fd < 0)
    {
        perror("open tttt fail");
        exit(-1);
    }
    lseek(fd ,4095,SEEK_SET);
    write(fd , " ",1);
    close(fd);

    return 0;
}

