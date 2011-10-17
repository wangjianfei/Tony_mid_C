#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void sys_err(char *str,int fd)
{
    write(fd,str,strlen(str));
    exit(-1) ;
}

int main(int argc, const char *argv[])
{
   int fd; 
   if(argc != 2)
   {
        sys_err("./a.out file\n",1);
   }
   fd = open(argv[1],O_RDWR|O_CREAT|O_EXCL);
   if(fd < 0)
   {
        sys_err("open file fail\n",1);
   }
   sys_err("abcdef\n",fd); 
   close(fd);
    return 0;
}

