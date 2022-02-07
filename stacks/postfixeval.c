#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10
struct stack{
	int top;
	int ch[50];
};

void push(int n,struct stack *s)
{
	if(s->top==MAX-1){
		printf("Overflow\n");
		return;
	}
	else
	{
		s->ch[++(s->top)]=n;		
	}
}

int pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("Stack underflow\n");
		return NULL;
	}
	else	
		return s->ch[(s->top)--];
}

int main()
{
	struct stack opstack;
    opstack.top=-1;
	char inpstr[20];
	printf("Enter input string\n");
	scanf("%s",inpstr);
	int i=0,val;
	char op1, op2;
	while(inpstr[i]!='\0')
	{
		char token=inpstr[i];
		if(isdigit(token))
			push((token-48),&opstack);      //48 because char array uses ascii for int '0'=48...
		else
		{
			op2=pop(&opstack);
			op1=pop(&opstack);
			switch(token)
			{
				case '+' :
				{
					val=op1+op2;
					break;
				}
				case '-':
				{
					val=op1-op2;
					break;
				}
				case '*':
				{
					val=op1*op2;
					break;
				}
				case '/':
				{
					val=op1/op2;
					break;
				}
				case '^':
				{
					val=op1^op2;
					break;
				}
			}
			push(val,&opstack);
		}
        i++;
	}
	printf("Answer is %d",pop(&opstack));
}

	
