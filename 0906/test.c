#include <stdio.h>
typedef struct 
{
    char b[10];

}stu;

int exercise(int a[3][4] )
{
    int i = 0;
    int j = 0;
    for(i = 0;i < 3;i++)
    {
        for(j = 0; j< 4;j++)
        {
            printf("  %d",a[i][j]);
        }
    }
    printf("\n");
    return 0;
}
int main(int argc, const char *argv[])
{
   /* stu a1 = {"abcdefg"};

    stu b1;
    b1 = a1;
    printf(" %s\n",b1.b);*/
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    exercise(a);
    return 0;

}

