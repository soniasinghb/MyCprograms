#include<stdio.h>

struct node
{
    int data;
    struct node *link;
};
struct queue
{
    struct node *front;
    struct node *rear;
};
void initq(struct queue *);
void addq(struct queue*, int n);
int delq(struct queue*);
void deleteq(struct queue*);

void main()
{
    struct queue q;

    initq(&q);
    addq(&q,10);
    addq(&q,9);
    addq(&q,8);
    int del=delq(&q);
    if(del!=NULL)
        printf("item deleted: &d\n",del);
    deleteq(&q);
}
void initq(struct queue *p)
{
    p->front=p->rear=NULL;
}

void addq(struct queue *p,int n)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=n;
    temp->link=NULL;
    
    if(p->front==NULL)
    {
        p->front=p->rear=temp;
        return;
    }
    p->rear->link=temp;
    p->rear=p->rear->link;
}
int delq(struct queue *p)
{
    int num;
    struct node *temp;

    
}