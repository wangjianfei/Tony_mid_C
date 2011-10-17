#include <stdio.h>

int main(int argc, const char *argv[])
{
    volatile int num = 5;
    while(num)
    {
        num--;
        printf("%d", num);
    }
    return 0;
}

