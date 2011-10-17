#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * my_strstr(char *src ,char *dest)
{
    int i = 0;
    char *temp = dest;
    i = strlen(dest);
    int num = 0;
    while(*src != '\0')
    {
        if(*src == *dest)
        {
            src++;
            dest++;
            num++;
            if(num == i)
            {
      //          printf("%s\n",src-i);
              //  dest = temp;
              //  num =0;
              return (src-i);
            }
            continue;
        }
        if(num > 0)
        {
            src = src-num;
            dest = temp;
            num =0;
        }
        src++;
    }
    return NULL;
}
int main(int argc,  char *argv[])
{
    char *my_str = NULL;
    char a[]="tai yuan gong ye xue yuan";
    if(argc == 1)
    {
        printf("input a.out substring\n");
        exit(0);
    }
    char *b = argv[1];
    my_str = my_strstr(a,b);
    if(my_str == NULL)
    {
        printf("noting match\n");
    }
    else
    {
        printf("%s\n",my_str);
    }
//    my_strstr(a,b);
    return 0;
}

