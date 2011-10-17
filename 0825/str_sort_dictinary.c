#include <stdio.h>
#include <stdlib.h>

char str[27]="abcdefghijklmnopqrstuvwxyz";

int str_num_word(char *p)
{
    int flag = 0;
    while(*p != '\0')
    {
        if(*p == ' ')
        {
            p++;
            flag++;
        }
        p++;
    }
    flag++;
    printf("%d\n",flag);
    return flag;
}

int str_word_sort(char *p)
{
    int i = 0;
    int flag = 0;
    flag = str_num_word(p);
    if(*p == '\0')
    {
        printf("string is NULL\n");
        exit(0);
    }
    for(i = 0;i <flag;i++)
    {
        if(*p)
    }
}

int main(int argc, const char *argv[])
{
    
    char str1[]="what do you want to say";
    return 0;

}

