#include<stdlib.h>		//Not Working for if no. is not present
#include<stdio.h>
typedef struct node
{
int data;
struct node* next;
}node;

void add(node **p,int v)
{
node *temp,*var;
var=*p;
 node* newnode=(node* )malloc(sizeof(node));
 newnode->data=v;
  if(*p==NULL)
  {
	*p=newnode;
	newnode->next=newnode;
  }
	else
	{
	temp=(*p)->next;
	newnode->next=temp;
	var->next=newnode;
	*p=newnode;
	}
}
void display(node *p)
{
node *var=p->next;
node *temp=var;
do
{
printf("%d\t",temp->data);
temp=temp->next;
}while(temp!=var);
}
void delete(node **p,int val)
{
	node *temp=(*p)->next,*prev,*var;
	if(temp->data==val)
	{
		(*p)->next=temp->next;
		free(temp);
	}
	else if((*p)->data==val)
	{
		var=temp;
		while(var->next->data!=val)
		{
			var=var->next;
		}
		var->next=temp;
		(*p)=var;
	}
	else
	{
	do
	{
		if(temp->data==val)
		{
			break;
		}
		prev=temp;
		temp=temp->next;
	}while(temp!=(*p)->next);
	prev->next=temp->next;
	free(temp);
	}
}
int insert(node **p,int val,int valdal)
{
	node *first,*prev,*temp,*first1;
	first=(*p)->next;
	first1=first;
	
	node *newno=(node *)malloc(sizeof(node));
	newno->data=valdal;
	if((*p)->next->data==val)
	{
		temp=first1->next;
		first1->next=newno;
		newno->next=temp;
		return 1;
	}
	if((*p)->data==val)
	{
		temp->next=newno;
		newno->next=first1;
		(*p)=newno;
		return 1;
	}
	else
	{
	do
	{
		if(first->data==val)
		break;
		prev=first;
		first=first->next;
	}while(first!=(*p)->next);
	temp=first->next;
	first->next=newno;
	newno->next=temp;
	return 1;
	}
	return 0;
}
void main()
{
node *first=NULL;
add(&first,1);
add(&first,2);
add(&first,3);
add(&first,4);
add(&first,5);
add(&first,6);
add(&first,7);
insert(&first,7,105);
insert(&first,105,24);
//delete(&first,10);
display(first);
}
