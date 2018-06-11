#include<stdio.h>
typedef struct node
{
	int data;
	struct node * next;
} Node;
void add(Node **p,int val)
{
	Node *var;
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=val;
	temp->next=NULL;
	if(*p==NULL)
	{
		*p=temp;
	}
	else
	{
		var=*p;
		while(var->next!=NULL)
		var=var->next;
		var->next=temp;
	}
}
int search(Node *p,int v)
{
	int flag=0;
	while(p!=NULL)
	{
		if(p->data=v)
		{
		flag=1;
		return 1;
		}
	}
	if(flag==0)
	return flag;
}
int count (Node *p)
{
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
int max(Node *p)
{
	int top;
	while(p!=NULL)
	{
	if(top<(p->data))
	top=p->data;
	p=p->next;
	}
	return top;
}
void main()
{
	char c='0';
	int temp,i=0;
	Node *first;
	first=NULL;
	for(;c!='n';i++)
	{
		scanf("%d",&temp);
		add(&first,temp);
	printf("Do You want to Continue");
	scanf(" %c",&c);
	}
	printf("%d%d",count(first),max(first));
}
