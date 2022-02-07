#include <stdio.h>
#include<stdlib.h>
#define MAX 10
struct stack{           //Stack elements in a structure
    int a[MAX];
    int top;
};

void display(struct stack s)        //func to display all elements of stack
{
    printf("Elements of array are:");
    while(s.top!=-1)
        printf(" \t%d",s.a[s.top--]);
}

void push(struct stack *s,int n)    //function push for primitive operation (push(ele)) on stack
{
    if(s->top==MAX-1)
         printf("Stack overflow! Cannot insert\n");     //exception handling: stack is full
    else{
        s->top++;
        s->a[s->top]=n;
    }
}

void pop(struct stack *s1)      //function pop for primitive operation (pop()) on stack
{
    if(s1->top==-1)
        printf("Underflow! Cannot pop\n");         //exception handling: stack is empty
    else{
    printf("Element popped is %d\n",s1->a[s1->top]);
    s1->top--;
    }
}

int poptopele(struct stack *s1)     //func to pop top element and return it
{
        int x= s1->a[s1->top--];
        return x;
}

void thirdelefromtop(struct stack *s){      //function to print 3rd element from to of stack
struct stack s1;        //temporary stack s1
s1.top = 0;         //initialization of top pointer of temporary stack to 0
int y;

int n=(s->top);
if(n<3){            //handling exception when number of elements is stack < 3
printf("Not possible: elements less than 3!!\n");
return;
}

push(&s1,poptopele(s));         //pop top 2 elements from stack s and push into temporary stack s1
push(&s1,poptopele(s));
y = s->a[s->top - 1];       //using the top pointer assign value of 3rd top ele to var y
printf("3rd element from top y = %d\n",y);
push(s,poptopele(&s1));         //push the 2 elements into stack s by popping from temp stack s1
push(s,poptopele(&s1));
}

void thirdelefrombottom(struct stack *s1)        //func to print bottom 3rd ele
{
    struct stack s2;        //temporary stack s2
    int y;
    s2.top=0;       //initialization of top pointer of temporary stack to 0
    while(s1->top!=-1)      //adding all elements of stack1 to stack2
        s2.a[s2.top++]=s1->a[s1->top--];

    y=poptopele(&s2);
    y=poptopele(&s2);
    y=poptopele(&s2);       //y is now the third popped element from stack2 which is 3rd element from bottom of og stack
    printf("Third element from bottom is y= %d\n",y);
}

int main()
{
    struct stack s;
    s.top=-1;
    int a,n;
    while(1)
    {
        printf("\nEnter function to be performed\n1-Push 2-Pop 3-display 4-display third ele from bottom 5-display third element from top 6-EXIT\n");
        scanf("%d",&a);
        switch(a)
    {
        case 1: {
                printf("Enter element to be pushed\n");
                scanf("%d",&n);
                push(&s,n);
                break;
        }
        case 2: {
                printf("Enter number of elements to be popped\n");
                int m;
                scanf("%d",&m);
                for(int i=0;i<m;i++)
                    pop(&s);    
        }
        case 3: {
            display(s);
            break;
        case 4: {
            if(s.top<2)
                printf("Number of elements less than 3, cannot print 3rd element");
            else
                thirdelefrombottom(&s);
            break;
        }
        case 5: {
            thirdelefromtop(&s);
            break;
        }
        case 6: exit(0);
        }
    }
    }
    return 0;
}

