#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

int length(struct node *q){
    static int l=0;
    if(q==NULL)
        return(0);
    else
        l=1+length(q->link);
    return(l);
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
int main()
{
    struct node *p;
    p=NULL;
    append(&p,1);
    append(&p,2);
    append(&p,3);
 
    int l;
    l=length(p);
    printf("%d",l);
}