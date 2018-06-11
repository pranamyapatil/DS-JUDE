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
	char ch[10];
	int temp=0,i=0;
	printf("Enter the String\n");
	scanf("%s",ch);
	while(ch[i]!=0)
	{
		temp=push(&s,ch[i++]);
		printf("%d\n",peek(s));
	}
	temp=0;i=0;
	printf("POP\n");
	while(ch[i]!=0)
	{
		if(ch[i++]!=pop(&s))
		break;
		/*else
		//printf("%c\n",ch[i]);*/
	}
	if(s.top==-1)
	printf("It is Pallindrome\n");
	else
	printf("It is not a Pallindrome\n");
}
