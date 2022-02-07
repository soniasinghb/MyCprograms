/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#define MAX 15
struct stack{
    int a[MAX];
    int top;
}s1;

void push(int);
void pop();
int topele();
void thirdelefromtop();
int main()
{
    s1.top=-1;
  
    int a,n;
    while(1)
    {
    printf("\nEnter function to be performed\n1-Push 2-Pop 3-display 4-EXIT\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1: {
                printf("Enter element to be pushed\n");
                scanf("%d",&n);
                push(n);
                break;
        }
        case 2: {
                printf("Enter number of elements to be popped\n");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                    pop();
                break;
        }
        case 3: {
            printf("Elements of array are:");
            while(s1.top!=-1)
            {            
                printf(" \n%d",s1.a[s1.top]);
                s1.top--;
            }
            break;
        case 4: exit(0);
        }
    }
    }
}
void push(int n)
{
    if(s1.top==MAX-1)
        printf("Stack overflow! Cannot insert\n");
    else
        s1.a[++s1.top]=n;
}

void pop()
{
    if(s1.top==-1)
        printf("Underflow! Cannot pop\n");
    else{
    printf("Element popped is %d\n",s1.a[s1.top]);
    s1.top--;
    }
}

int topele()
{
    if(s1.top==-1)
        return;
    else
        return s1.a[s1.top];
}

void thirdelefromtop()
{
    struct stack s2;
    s2.top=0;
    while(s1.top!=-1)
        s2.a[s2.top++]=s1.a[s1.top--];
    int n;
    n=s2.top;
    if(n<3)
    {
        printf("Number of elements less than 3, cant print 3rd element");
        return;
    }
    else{
        pop();
    }
}

