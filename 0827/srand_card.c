#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int riffle(int (*p)[3])
{
 /*   int flag[52]={0};
    int num = 52;
    int tmp;
    int *q = (int *)p;
    srand(time(NULL));
    while(num > 0)
    {
        tmp = rand()%52;
        if(flag[tmp] == 1)
        {
            continue;
        }
        else
        {
            flag[tmp] = 1;
            *q = tmp;
            q++;
            num--;
        }
    }*/

    srand(time(NULL));
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    for(i = 0;i < 2; i++)
    {
        for(j= 0;j <3; j++)
        {
          lp: (*(p+i))[j] = rand()%6;
          m = 0;
          n = 0;
            for(m = 0;m <2 ;m++)
            {
                for(n = 0;n < j;n++)
                {
                    if((*(p+i))[j] == (*(p+m))[n])
                    {
                        goto lp;
                    }
                }
            }
        }
    }
    return 0;
}

int printf_fun(int (*p)[3])
{
    int *q = (int *)p;
    int i = 0;
    for(i = 1;i <= 6;i++,q++)
    {
        printf("%d  ",*q);
      /*  if(i%13 ==0)
        {
            printf("\n");
        }
    }*/
    printf("\n");
    return 0;
}

int main(int argc, const char *argv[])
{
    int arr[2][3];
    int i =0;
    int j = 0;
    for(i = 0; i< 2;i++)
    {
        for(j = 0 ;j < 3;j++)
        {
            arr[i][j] = -1;
        }
    }
    printf_fun(arr);
    riffle(arr);
    printf_fun(arr);
    return 0;
}

//    perflop(arr,4)
//    return 0;
//int (*p)[13]
//a[4][13]
