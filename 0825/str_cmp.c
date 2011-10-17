#include <stdio.h>

int my_str_cmp(char *p, char *q)
{
   
    while((*p != '\0')||(*q != '\0'))
    {
        if(*p == *q)
        {
            p++;
            q++;
        }
        else 
        {
          
            return 1;
        }
    }
/*    if(*q == '\0')
    {
         return 1;
    }
    else
    {
        return 0;
    }*/
    return 0;
}

int main(int argc, const char *argv[])
{
    char str1[] = "abcdefgh";
    char str2[] = "abcdef";
    char *p = str1;
    char *q = str2;
    printf("%d\n",my_str_cmp(p,q));
    return 0;
}

