#include <stdio.h>

int str_word_num(char *p)
{
    int flag =0;
    while(*p != '\0')
    {
        if(*p == ' ')
        {
           
            flag++;
        }
        p++;
    }
    flag++;
    return flag;
}

int str_most_length_word(char *p)
{
    char *temp = p;
    int i = 0;
    int num = 0;
    int flag = 0;
    int counter = 0;
    int word = 0;
    num = str_word_num(p);
    for(i = 0;i < num;i++)
    {
        while(*p != ' ')
        {
            if(*p == '\0')
            {
                break;
            }
            flag++;
            p++;
        }
        if(flag > counter)
        {
            counter = flag;
            word = i;
        }
        p++;
        flag= 0;
    }
    i = 0;
    while(*temp != '\0')
    {
        if(i == word)
        {
            while((*temp != ' ' )&&(*temp != '\0'))
            {
                printf("%c",*temp);
                temp++;
            }
            printf("\n");
            break;
        }
        if(*temp == ' ')
        {
            i++;
        }
        temp++;
    }
    printf("%d\n",counter);
    return 0;
}

int main(int argc, const char *argv[])
{
    char str[] = "taiyu ykjljlkjlkjlkj  xue yuanyuan";

    str_most_length_word(str);
    return 0;
}

