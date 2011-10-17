#include <stdio.h>
#include <string.h>

char *itoa(int a)
{
    char str[1024];
    char *p = str;
    int i = 0;
    char temp;
    int len = 0;
    while(a)
    {
        str[i] = a%10+'0';
        i++;
        a = a/10;
    }
    str[i] = '\0';
    len = strlen(str);
    for(i = 0;i < len/2;i++)
    {
        temp = str[i];
        str[i] = str[len- 1-i];
        str[len-1-i] = temp;
    }
    return p;
}

int main(int argc, const char *argv[])
{
    int a = 23402;
    char *str;
    str = itoa(a);
    printf("%s\n",str);
    printf("%d\n",strlen(str));
    return 0;
}

