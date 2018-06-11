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
void reverse(node *p)
{
	int i,j,count =0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	printf("Enter");
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			int t;
			t=p->data;
			p->data=p->next->data;
			p->next->data=t;
			p=p->next;
		}
	}
}
void main()
{
	node *first;
	add(&first,1);
	add(&first,2);
	add(&first,3);
	add(&first,4);
	add(&first,5);
	add(&first,6);
	add(&first,7);
	reverse(first);
	display(first);
}
