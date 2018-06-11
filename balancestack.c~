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
	char ch[10],temp;
	int i=0,flag=0;
	printf("Enter the String\n");
	scanf("%s",ch);
	for(i=0;ch[i];i++)
	{
		if(ch[i]=='('||ch[i]=='{'||ch[i]=='[')
		{
			push(&s,ch[i]);
		}
		if(ch[i]==')'||ch[i]=='}'||ch[i]==']')
		{
			temp=peek(s);
			switch(ch[i])
			{
			case ')':if(temp=='(')
					pop(&s);
				else
				flag=1;
				break;
			case '}':if(temp=='{')
					pop(&s);
				else
				flag=1;
				break;
			case ']':if(temp=='[')
					pop(&s);
				else
				flag=1;
				break;
			}
		}
	}
	if(flag==0&&isEmpty(s))
	{
		printf("it is balanced\n");
	}
	else
		printf("it is unbalanced\n");					
}
