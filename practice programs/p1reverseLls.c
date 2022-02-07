#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void addatbeg(struct node**, int);
void reverse(struct node**);
void display(struct node*);

int main()
{
    struct node *p;
    p=NULL;
    addatbeg(&p,7);
    addatbeg(&p,5);
    addatbeg(&p,3);
    addatbeg(&p,1);
    addatbeg(&p,0);
    addatbeg(&p,9);
    display(p);
    reverse(&p);
    display(p);
    return 0;
}

void addatbeg(struct node **q, int num)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->link=*q;
    *q=temp;
}

void reverse(struct node **x)
{
    struct node *q, *r, *s;
    q=*x;
    r=NULL;
    while(q!=NULL)
    {
        s=r;
        r=q;
        q=q->link;
        r->link=s;
    }
    *x=r;
}

void display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->link;
    }
    printf("\n");
}