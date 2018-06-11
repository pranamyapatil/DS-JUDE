#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}node;
void add(node **p,int val)
{
	node *temp,*var;
	var=*p;
	temp=(node *)malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	if(*p==NULL)
	{
		*p=temp;
	}
	else
	{
		while(var->next!=NULL)
		{
			var=var->next;
		}
		var->next=temp;
	}
}
void display (node *p)
{
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void delete(node *p)
{
	int i,j,dat;
	node *temp;
	for(i=0;p!=NULL;i++)
	{
		dat=p->data;
		temp=p->next;
		for(j=0;temp->next!=NULL;j++)
		{
			if(temp->next->data==dat&&temp->next->next!=NULL)
			{
				temp->next=temp->next->next;		//Decision Point works when last not repeating
			}
			else if(temp->next->data==dat&&temp->next->next==NULL)
			temp->next=NULL;
			temp=temp->next;
		}
		p=p->next;
	}
}
void frees(node **t)
{
	node *temp;
	while((*t)->next!=NULL)
	{
		temp=*t;
		*t=(*t)->next;
		free(temp);
	}
}		
void main()
{
	node *first;
	first=NULL;
	add(&first,1);
	add(&first,1);
	add(&first,2);
	add(&first,2);
	add(&first,3);
	add(&first,4);
	add(&first,1);
	delete(first);
	display(first);
	frees(&first);
}
