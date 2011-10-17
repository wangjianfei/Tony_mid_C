#include <stdio.h>

int main(int argc, const char *argv[])
{
    char *a = "abcdef";
    int b = 0x12345678;
    int i = 0;
    printf("%x\n",a);
    printf("%x\n",a+1);
    printf("%u\n",a+2);
    printf("%u\n",a+3);
    for (i = 0; i < 4; i++)
    {
        printf("%x\n",*((char *)&b+i));
    }
    return 0;
}

