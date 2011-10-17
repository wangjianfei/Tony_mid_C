#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int n;
    char buf[10];
    n = read(STDIN_FILENO,buf,10);
    if(n < 0)
    {
        perror("open error");
        exit(-1);
    }
    printf("%d\n",n);
    write(STDOUT_FILENO,buf,n);

    return 0;
}

