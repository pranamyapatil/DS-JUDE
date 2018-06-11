#include<stdio.h>
#define size 10
typedef struct stack
{
	int data[size],top;
}stack;
int push(stack *s,int val)
{
if(s->top!=size-1)
{
	s->data[++(s->top)]=val;
	return 1;
}
else
	return 0;
}
int isEmpty(stack s)
{
if (s.top==-1)
	return 1;
else
	return 0;
}
int pop(stack *s)
{
	if(!isEmpty(*s))
		return s->data[s->top--];
	else
		return -1;	
}
int peek(stack s)
{
	return s.data[s.top];
}
void main()
{
	stack s;
	s.top=-1;
	int temp=0,i=0;
	do
	{
		temp=push(&s,i++);
		printf("%d\n",peek(s));
	}while(temp!=0);
	temp=0;
	printf("POP\n");
	while(temp!=-1)
	{
		printf("%d\n",temp=pop(&s));
	}
}
