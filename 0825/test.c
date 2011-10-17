#include <stdio.h>
#define NUM 100
const char num = 6;
int init = 7;
int uninit;

int main(int argc, const char *argv[])
{
   // char *p = "hello";   
/*    uninit = 5;        printf("%x\n",&num);
    printf("%x\n",&init);

    printf("%x\n",&uninit);
    printf("%d\n",uninit);
    printf("%x\n",p);
    printf("jkljklj");
    while(1);*/
    char name[10];
    gets(name);
    printf("%d\n",NUM);
    printf("%s\n",name);
    return 0;
}

