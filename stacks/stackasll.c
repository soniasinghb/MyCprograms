#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *link;
};
void push(struct node**,int);
int pop(struct node**);
void delstack(struct node**);
int main()
{
    struct node *s=NULL;
    int n;

    push(&s,7);
    push(&s,3);
    push(&s,8);
    push(&s,6);
    n=pop(&s);
    if(n!=NULL)
        printf("Item popped%d\n",n);
    n=pop(&s);
    if(n!=NULL)
        printf("Item popped%d\n",n);
    n=pop(&s);
    if(n!=NULL)
        printf("Item popped%d\n",n);

    delstack(&s);    
}

void push(struct node **p,int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));

    
}