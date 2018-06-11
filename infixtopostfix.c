#include<stdio.h>
typedef struct stack
{
	char data[100];
	int top;
}stack;
typedef struct vals
{
	char var;
	int val;
}vals;
char peak(stack s)
{
	return s.data[s.top];
}
void push(stack *p,char val)
{
	p->data[++p->top]=val;
}
int isEmpty(stack s)
{
	return s.top==-1;
}
char pop(stack *p)
{
	if(!isEmpty(*p))
	{	printf("In POP\n");
		return p->data[(p->top)--];
	}
return -1;
}	
int preced(char a)
{
	switch(a)
	{
		case '/':
		case '*':
		case '%':return 4;
		case '+':
		case '-':return 3;
		case ')':
		case '(':return 1;
		default:return 0;
	}
}
void infixtopostfix(char *infix,char *post)
{
printf("Hello\n");
int i=0,j=0;
stack s;
s.top=-1;
for(i=0;infix[i]!=0;i++)
{
	if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'||infix[i]=='('||infix[i]==')')
	{
		if(isEmpty(s)||preced(infix[i])>preced(peak(s))||infix[i]=='(')
			push(&s,infix[i]);
		else if(infix[i]==')')
		{
			while(peak(s)!='(')
				post[j++]=pop(&s);
			pop(&s);
		}
		else 
		{
			while(s.top!=-1&&preced(infix[i])<=preced(peak(s)))
				post[j++]=pop(&s);
			push(&s,infix[i]);
		}
	}
	else
	{
		post[j++]=infix[i];
	}

}
while(!isEmpty(s))
{
post[j++]=pop(&s);
}
post[j]=0;
printf("o/p%s\n",post);
}
/*int balance(char arr[100])
{
	int i=0;
	stack s;
	while(arr[i]!=0)
	{
		if(arr[i]=='('||arr[i]=='{'||arr[i]=='[')
			push(&s,arr[i]);
		else if(arr[i]==')'||arr[i]=='}'||arr[i]==']')
		{
			char t=peak(s);
*/

int toInt(char ch,vals v[10])
{
	int i=0;
	while(ch!=v[i].var){
	i++;
	}
	return v[i].val;
}
int toEval(char arr[100],vals v[10] )
{
	int i=0;
	stack s;
	s.top=-1;
	int oper1,oper2,res;
	while(arr[i]!=0)
	{
		if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'||arr[i]=='%')
		{
			oper2=(pop(&s));
			oper1=(pop(&s));
			switch(arr[i])
			{
				case '+':res=oper1+oper2;break;
				case '-':res=oper1-oper2;break;
				case '*':res=oper1*oper2;break;
				case '/':res=oper1/oper2;break;
				case '%':res=oper1%oper2;break;
			}
		}
		else
		{
			res=toInt(arr[i],v);
			push(&s,res);
		}
		i++;	
	}
	return pop(&s);
}		
int valisFound(char ch,vals v[10])
{
	int i=0,flag=0;
	while(v[i].var!=0)
	{
		if(ch==v[i].var)
			flag=1;
i++;
	}
return flag;
}
void main()
{
char ch1[100],ch2[100];
vals v[10];int i=0,temp,j=0;
printf("Enter the String\n");
scanf("%s",ch1);
infixtopostfix(ch1,ch2);
while(ch2[i]!=0)
{
	if(ch2[i]!='+'&&ch2[i]!='-'&&ch2[i]!='*'&&ch2[i]!='/'&&ch2[i]!='%'&&!valisFound(ch2[i],v))
	{
		printf("Enter the value of %c:\t",ch2[i]);
		scanf("%d",&temp);
		printf("hogaya\n");
		v[j].var=ch2[i];
		v[j].val=temp;
		v[++j].var=0;
	}
	i++;
}
int res=toEval(ch2,v);
printf("%d\n",res);
}
