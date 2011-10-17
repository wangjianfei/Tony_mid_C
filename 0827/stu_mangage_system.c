#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int num;
    char name[10];
    struct student *next;
};

typedef struct student stu;



stu *insert_node(stu *p)
{
    char a[10];
    char b[10];
    stu *head = p;
    stu *q = NULL;
    q =  malloc(sizeof(stu));
    if(q == NULL)
    {
        perror("insert node");
        exit(0);
    }
    printf("input a node: \n");
    fgets(a,10,stdin);
    a[strlen(a)-1]='\0';
    q->num = atoi(a);
    printf("intput a name:\n");
    fgets(b,10,stdin);
    b[strlen(b)-1] = '\0';
    strcpy(q->name,b);

    q->next = NULL;
    if(p == NULL)
    {
        return q;
    }
    if(q->num < p->num)
    {
        q->next = head;
        head = q;
        return head;
    }
    while(p->next != NULL)
    {
        if(p->next->num > q->num)
        {
            break;
        }
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
    
    return head;

}

int print_link(stu *p)
{
    if(p == NULL)
    {
        printf("this is a null link\n");
    }
    while(p != NULL)
    {
        printf("%d  ",p->num);
        printf("%s\n",p->name);
        p = p->next;
    }
    return 0;
}

int num(stu *p)
{
    
    printf("%d\n",p->num);
    return 0;
}

int name(stu *p)
{
    printf("%s\n",p->name);
    return 0;
}

int main(int argc, const char *argv[])
{
    int i = 0;
    stu *head = NULL;
    head = insert_node(head);
    print_link(head);
    char a[10];
    int (*p[10])(stu *) = {name,num};
    while(1)
    {
    printf("input 1 ,output num  intput 0,output name\n");

         fgets(a,10,stdin);
         a[strlen(a)-1] = '\0';
         i = atoi(a);
         if(i > 1)
         {
            break;
         }
         p[i](head);
         
    }
    return 0;
}

