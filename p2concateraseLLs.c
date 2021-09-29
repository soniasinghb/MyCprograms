#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};

void append(struct node**, int);
void display(struct node*);
void concat(struct node**, struct node**);
struct node *erase(struct node *);

int main()
{
    struct node *first, *second;
    first=NULL;
    second=NULL;
    append(&first,1);
    append(&first,2);
    append(&first,3);
    append(&first,4);
    append(&second,5);
    append(&second,6);
    append(&second,7);
    append(&second,8);
    display(first);
    display(second);
    concat(&first,&second);
    display(first); 
    first=erase(first);
    return 0;
}

void append(struct node **q, int num)
{
    struct node *temp;
    temp=*q;
    if(*q==NULL)
    {
        *q=(struct node*)malloc(sizeof(struct node));
        temp=*q;
    }
    else
    {
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=(struct node*)malloc(sizeof(struct node));
        temp=temp->link;
    }
    temp->link=NULL;
    temp->data=num;
}

void concat(struct node **p, struct node **q)
{
    struct node *temp;
    if(*p==NULL)
        *p=*q;
    else
    {
        if(*q!=NULL)
        {
        temp=*p;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=*q;
        }
    }
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


struct node*(erase(struct node *q))
{
    struct node *temp;
    while(q!=NULL)
    {
        temp=q;
        q=q->link;
        free(temp);
    }
    return NULL;
}
