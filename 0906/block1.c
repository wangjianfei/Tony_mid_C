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
    int fd;
    fd = open("aaaa",O_RDWR);
    lseek(fd,99,SEEK_SET);
    write(fd," ",1);
    close(fd);
    return 0;
}

