#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int data;
struct node* next;
};

typedef struct node *NODE;

struct node *getnode()
{
struct node *p;
p = (NODE) malloc(sizeof(struct node));
if(p== NULL)
{
 printf("Insufficient Memory");
 exit(0);
}
p->next = p;
return p;
}

void insert_after_head(NODE head, int x)

{

struct node* p ;

p= getnode();

p->data =x;

p->next=head->next;

head->next=p;

}

/* Adds contents of two linked lists and return the head node of  resultant list */

NODE addLists(NODE l1, NODE l2,NODE l3)

{

NODE p,q;

NODE prev = NULL;

int carry , sum,digit;

p=l1->next;

q=l2->next;

carry=0;

while (p!= l1 && q != l2) //while a node exists in both lists  
{

 sum = carry + p->data + q->data;

 carry = sum/10;

 digit = sum%10;

 insert_after_head(l3,digit);

 p=p->next;

 q=q->next;

 

}

while(p!=l1)

{

 sum = carry + p->data ;

 carry = sum/10;

 digit = sum%10;

 insert_after_head(l3,digit);

 p=p->next;

}

while(q!=l2)

{

 sum = carry + q->data ;

 carry = sum/10;

 digit = sum % 10;

 insert_after_head(l3,digit);

 q=q->next;

}

if (carry != 0)

 insert_after_head(l3,carry);

}

// A utility function to print a linked list  
void printList(NODE head)

{

NODE p;

p= head->next;

printf("\n");

while(p != head)

{

 printf("%d", p->data);

 p = p->next;

}

}

void Read_Number(NODE head)

{

char number[100];

int i,digit;

scanf("%s",number);

i =0;

while(number[i]!='\0')

{

 digit=number[i] - 48; // char to numeric conversion

 insert_after_head(head,digit);   i++;

}

}

int main(void)

{

NODE l1 ,l2,l3;

// Header nodes

l1=getnode();

l2=getnode();

l3=getnode();

printf("Enter the first number :");  Read_Number(l1);

printf("Enter the second number :");  Read_Number(l2);

 

addLists(l1, l2,l3);

printf("Sum is ");

printList(l3);

return 0;

}