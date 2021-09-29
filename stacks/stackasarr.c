#include<stdio.h>
#include<stdlib.h>
struct stack{
    int array[10];
    int top;
};
void initstack(struct stack*);
void push(struct stack*,int item);
int pop(struct stack*);

int main()
{
    struct stack s;
    int n;
    initstack(&s);
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
    n=pop(&s);
    if(n!=NULL)
        printf("Item popped%d\n",n);
}
void initstack(struct stack *p)
{
    p->top=-1;
}

void push(struct stack *p, int item)
{
    if(p->top==9)
    {
        printf("Stack is full\n");
        return;
    }
    p->top++;
    p->array[p->top]=item;
}

int pop(struct stack *p)
{
    if(p->top==-1)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    int c;
    c=p->array[p->top];
    p->top--;
    return c;
}