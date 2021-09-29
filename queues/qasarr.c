#include<stdio.h>

struct queue
{
    int arr[10];
    int front, rear;
};

void init(struct queue*);
void addq(struct queue*, int);
int delq(struct queue*);

void main()
{
    struct queue q;

    init(&q);
    addq(&q,10);
    addq(&q,10);
    addq(&q,10);
    addq(&q,10);

    int del;
    del=delq(&q);
    if(del!=NULL)
        printf("Item deleted : %d",del);
    del=delq(&q);
    if(del!=NULL)
        printf("Item deleted : %d",del);
    del=delq(&q);
    if(del!=NULL)
        printf("Item deleted : %d",del);
    del=delq(&q);
    if(del!=NULL)
        printf("Item deleted : %d",del);
    del=delq(&q);
    if(del!=NULL)
        printf("Item deleted : %d",del);
        
}

void init(struct queue *p)
{
    p->front=-1;
    p->rear=-1;
}

void addq(struct queue *p, int n)
{
    if(p->rear==9)
    {        printf("Queue is full");
             return;
    }

    p->rear++;
    p->arr[p->rear]=n;
    
    if(p->front==-1)
        p->front=0;
}

int delq(struct queue *p)
{
    int item;
    if(p->front==-1)
    {
        printf("Queue is empty");
        return NULL;
    }
    item=p->arr[p->front];

    /* p->arr[p->front]=0;? */

    if(p->front==p->rear)
        p->front=p->rear=-1;
    else
        p->front++;

    return item;
}