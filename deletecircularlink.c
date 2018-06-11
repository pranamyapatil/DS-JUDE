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
delete(&first,10);
display(first);
}
