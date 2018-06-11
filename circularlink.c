#include<stdlib.h>
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
display(first);
}
