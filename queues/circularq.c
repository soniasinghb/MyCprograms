#include <stdio.h>
#include <stdlib.h>

#define MAX 6

struct queue{
    int rear, front;
    int a[];
};

void enqueue(struct queue *q1, int n)
{
    if((q1->rear==MAX-1)&&(q1->front==0))
    {
        printf("Queue is full\n");
        return;
    }
    else if((q1->front==-1)&&(q1->rear==-1)){
        q1->front=q1->rear=0;
        q1->a[q1->rear]=n;
    }
    else if((q1->rear==MAX-1)&&(q1->front!=0))
    {
        q1->rear=0;
        q1->a[q1->rear]=n;
    }
    else{
        q1->rear++;
        q1->a[q1->rear]=n;
    }
}

void dequeue(struct queue *q)
{
    if((q->front==-1)&&(q->rear==-1))
    {
        printf("Queue is empty\n");
        return;
    }
    int val=q->a[q->front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else if(q->front==MAX-1)
        q->front=0;
    else
        q->front++;
    printf("%d is deleted\n",val);
} 

int main(){
    struct queue q1;
    int n;
    int a;
    q1.rear=q1.front=-1;
    while(1)
    {
        printf("\nEnter function to be performed\n1-Push 2-Pop 3-display 4-EXIT\n");
        scanf("%d",&a);
        switch(a)
    {
        case 1: {
                printf("Enter element to be added\n");
                scanf("%d",&n);
                enqueue(&q1,n);
                break;
        }
        case 2: {
                    dequeue(&q1);    
                    break;
        }
        case 3: {
            break;
        case 4: exit(0);
        }
    }
    }
    return 0;
}