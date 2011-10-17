#include <stdio.h>

int str_length(char *p)
{
    int counter = 0;
    while(*p != '\0')
    {
        counter++;
        p++;
    }
    printf("%d\n",counter);
    return counter;
}

int str_search_most_char(char *p)
{
    char var;
    int length = 0;
    int i = 0;
    int j = 0;
    int flag = 1;
    int  num = 1;
    length = str_length(p);
    for(i = 0;i < length ;i++)
    {
        if(p[i] == 0)
        {
            continue;
        }
        for(j = i+1;j < length-i;j++)
        {
            if(p[i] == p[j])
            {
                flag++;
                p[j] = 0;
            }
        }
        if(flag > num)
        {
            num = flag;
            var = p[i];
            flag = 1;
        }

    }
    printf("%c\n",var);
    printf("%d\n",num);
    return  0;
}

int main(int argc, const char *argv[])
{
    char str[]="abcbbbbbbdabdaaa";
    str_search_most_char(str);
    return 0;
}

