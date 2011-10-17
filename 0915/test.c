#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int num = 0;
    alarm(1);
    while(1)
    {
        num++;
        usleep(1000);
        printf("   %d    ",num);
    }
    return 0;
}

