#include<stdio.h>
#include<stdlib.h>			//alphabets string i.e: A+B*C
#include<ctype.h>
#define MAX 20
struct stack{
	char st[20];
	int top;
};

void push(int n, struct stack *s)
{
	if(s->top==MAX-1)
	{
		printf("Overflow\n");
		return;
	}
	else
		s->st[++(s->top)]=n;
}

char pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("Underflow\n");
		return -1;
	}
	else	
		return s->st[(s->top)--];
}
int precedence(char c)									// prcd >= : 
{
	if(c=='(')							// means any operator can sit on top of a (
		return 0;
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='$' || c=='^')
		return 3;
    return -1;
}
int main()
{
	struct stack s1;
	char inf[20], post[20];
	
	printf("Enter the input string\n");
	scanf("%s",inf);
	char *e;
	e=inf;
	int i=0;
	
	while(*e!='\0')
	{
		char token=*e;
		if(isalpha(token))
			post[i++]=token;
		else if(token=='(')
				push(token,&s1);
		else if(token==')')
			{
				while((s1.st[(s1.top)--]!='(')&&(s1.top!=-1))
					post[i++]=pop(&s1);
				if(s1.top==-1){
					printf("Invalid expression\n");
					exit(1);
				}
			}
		else{
			if((token=='$'&&s1.top=='$')||(token=='^'&&s1.top=='^'))
			    push(token,&s1);
			else{
				while(precedence(s1.st[s1.top]) >= precedence(token))
					post[i++]=pop(&s1);
				push(token,&s1);
			}
		}
		e++;
	}
	printf("The answer is %s",post);
	return 0;
}

