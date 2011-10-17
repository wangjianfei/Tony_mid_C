#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct msg
{
    struct msg *next;
    int num;
};

struct msg *head;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *p)
{
    struct msg *mp;

    for(;;)
    {
        pthread_mutex_lock(&lock);
        while(head == NULL)
        {
            pthread_cond_wait(&has_product,&lock);//解除锁 同时阻塞

        }
        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&lock);
        printf("Consume %d\n",mp->num);
        free(mp);
        sleep(rand()%5);
    }
}



void *producter(void *p)
{
    struct msg *mp;
    for(;;)
    {
        mp = malloc(sizeof(struct msg));
        mp->num = rand()%1000+1;
        printf("Produce %d\n",mp->num);
        pthread_mutex_lock(&lock);
        mp->next = head;
        head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);//通过pthread_cond_signal唤醒上面阻塞的
                                            //pthread_cond_wait函数
        sleep(rand()%5);
    }
}

int main(int argc, const char *argv[])
{
    pthread_t pid,cid;

    srand(time(NULL));
    pthread_create(&pid,NULL,producter,NULL);
    pthread_create(&cid,NULL,consumer,NULL);
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
    return 0;
}

