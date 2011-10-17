#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int num;
int flag;
FILE *fp1,*fd2;
struct stat *f_stat;

void *pthread(void *arg)
{
    int num = *(void *)arg;
    lseek();
}



int main(int argc, const char *argv[])
{
    int pthread_num,i;
    int over_num;
    pthread_t tid,tid1;
    fp1 = fopen(argv[1],"r");
    if(fp1 == NULL)
    {
        perror("open argv[1]");
        exit(-1);
    }
    fp2 =fopen(argv[2],"w");
    if(fp2 == NULL)
    {
        perror("open argv[2]");
        exit(-1);
    }
    stat(argv[1],f_stat);
    fseek(fp2,f_stat->st_size,SEEK_SET) ;
    
     pthread_num = atoi(argv[3]);
     for(i= 0;i<pthread_num-1;i++)
     {
        pthread_create(&tid,NULL,pthread,(void *)&i);
     }

    pthread_create(&tid1,NULL,,);
    while(1)
    {
        pthread_join(tid,NULL);
        over_num++;
        if(over_num == pthread_num-1)
        {
            break;
        }
    }
    pthread_join(tid1i,NULL);

    return 0;
}

