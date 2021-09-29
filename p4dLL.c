#include<stdio.h>
#include<stdlib.h>
struct dnode
{
    struct dnode *prev;
    struct dnode *next;
    int data;
};
void append(struct dnode**, int);
void addatbeg(struct dnode**, int);
void addafter(struct dnode*,int,int);
void display(struct dnode*);
int main()
{
    struct dnode *p;
    p=NULL;
    append(&p,1);
    append(&p,2);
    append(&p,3);
    addatbeg(&p,7);
    addatbeg(&p,7);
    addatbeg(&p,7);
    addafter(p,4,0);
    addafter(p,5,0);
    addafter(p,6,0);
    display(p);
    return 0;
}

void append(struct dnode **s, int num)
{
    struct dnode *r, *q=*s;
    if(*s==NULL)
    {
        *s=(struct dnode*)malloc(sizeof(struct dnode));
        (*s)->prev=NULL;
        (*s)->next=NULL;
        (*s)->data=num;
    }
    else
    {
        while(q->next!=NULL)
            q=q->next;
        r=(struct dnode*)malloc(sizeof(struct dnode));
        r->prev=q;
        r->data=num;
        r->next=NULL;
        q->next=r;
        
    }
}

void addafter(struct dnode *q, int loc, int num)
{
    struct dnode *temp;
    for(int i=0;i<loc;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("Out of bounds\n");
            return;
        }
    }
    q=q->prev;
    temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=num;
    temp->prev=q;
    temp->next=q->next;
    temp->next->prev=temp;
    q->next=temp;
}

void addatbeg(struct dnode **s, int num)
{
    struct dnode *p;
    p=(struct dnode*)malloc(sizeof(struct dnode));
    p->prev=NULL;
    p->data=num;
    p->next=(*s);
    (*s)->prev=p;
    *s=p;
}

void display(struct dnode *p)
{
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}