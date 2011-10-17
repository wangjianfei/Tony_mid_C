#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i= 0;
    int j =0;
    int m = 0;
    int arry[10]={1,2,3,4,5,6,7,8,9,10};
    int arr[2][5];
    for(i = 0;i < 2;i++)
    {
        for(j = 0;j < 5;j++)
        {
            arr[i][j] = arry[m];
            m++;
            if(m%5==0)
            {
                printf("\n");
            }
            printf("  %d", arr[i][j]);
            
        }
    }
    return 0;
}

