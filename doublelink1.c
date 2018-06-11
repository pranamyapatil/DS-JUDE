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
			
			var=var->next;
		}
		var->next=temp;
		temp->prev=var;
		//printf("%u\t%u\t%u\n",var->prev,var);
	}
}
void display(node *p)
{
while(p->next!=NULL)
{
	p=p->next;
}
while(p!=NULL)
{
	printf("%d\t",p->data);
	p=p->prev;
}
}
void delete(node **p,int val)
{
	node *temp=*p,*var,*var1;
	while(temp->next!=NULL)
	{
		if(temp->data==val)
		{
			break;
		}
		temp=temp->next;
	}
	if(temp->next!=NULL&&(*p)->data!=val)
	{
		var1=temp->next;
		var=temp->prev;
		var->next=var1;
		var1->prev=var;
	}
	else if(temp->next!=NULL&&(*p)->data==val)
	{
		temp;
		*p=var1;
		var1->prev=NULL;
	}
	else if(temp->next==NULL&&temp->data==val)
	{
		var=temp->prev;
		var->next=NULL;
	}
}
void insertpo(node **p,int val,int po)			//position less than max value......
{
	node *var=*p;
	int count=1;
	node *t=(node *)malloc(sizeof(node));
	t->data=val;
	while(count<po)
	{
		var=var->next;
		count++;
	}
	if(po>1&&var!=NULL)
	{
	t->prev=var->prev;
	var->prev=t;
	t->next=var;
	/*t->prev=var;
	t->next=var->next;
	var->next=t;*/
	}
	else if(po==1)
	{
		var->prev=t;
		t->next=var;
		*p=t;
		t->prev=NULL;
	}
}
void insert(node **p,int val)
{
	node *t=(node *)malloc(sizeof(node));
	node *var,*temp;
	var=*p;
	t->data=val;
	while(var->next!=NULL)
	{
		if(var->data>val)
		break;
		var=var->next;
	}
	if((*p)->data<val&&var->next!=NULL)
	{
	t->prev=var->prev;
	var->prev=t;
	t->next=var;
	}
	else if((*p)->data>val)
	{
		t->next=*p;
		var->prev=t;
		*p=t;
	}
	else if(var->next==NULL&&var->data<val)
	{
		var->next=t;
		t->next=NULL;
		t->prev=var;
	}
}
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
	insert(&first,65);
	insertpo(&first,155,1);
	//delete(&first,20);
	display(first);
}
