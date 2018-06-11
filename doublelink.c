#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,* prev;
}node;
void add(node **p,int val)
{
	node *temp,*var=*p,* man=NULL;
	temp=(node *) malloc(sizeof(node));
	temp->data=val;
	temp->next=NULL;
	temp->prev=NULL;
	if(*p==NULL)
	{
		*p=temp;
		//man=*p;

	}
	else
	{
		while(var->next!=NULL)
		{
			man=var;
			var=var->next;
		}
		var->next=temp;
		var->prev=man;
		printf("%u\t%u\t%u\n",var->prev,var,var->next);
	}
}
void display(node *p)
{
while(p->next!=NULL)
{
	printf("%u\t%u\t%u\n",var->prev,var,var->next);
	p=p->next;
}
while(p!=NULL)
{
	printf("%u\t%u\t%u\n",var->prev,var,var->next);
	///*printf("%d\t",p->data);*/
	p=p->prev;
}
}
void frees()
{

void main()
{
	node *first;
	first=NULL;
	add(&first,10);
	add(&first,20);
	add(&first,30);
	add(&first,40);
	add(&first,50);
	add(&first,60);
	add(&first,70);
	add(&first,80);
	add(&first,90);
	add(&first,100);
	display(first);
}
