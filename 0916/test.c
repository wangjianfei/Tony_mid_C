#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int i = 20;
    int num = 0;
    while(i--)
    {
        printf("%d       ",(rand()%5));
    }
    return 0;
}


