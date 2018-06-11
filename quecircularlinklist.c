#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	int data;
	struct node* next;
}node;
void insert(node**p,int val)
{
	node *temp,*newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	if(*p==NULL)
	{
		*p=newnode;
		(*p)->next=newnode;
	}
	else
	{
		temp=(*p)->next;
		(*p)->next=newnode;
		newnode->next=temp;
		*p=newnode;
	}
}
int dequeue(node **p)
{
	node *temp;int t;
	if(*p==NULL)
		return -1;
	temp=(*p)->next;	
	if(*p==(*p)->next)
	{
		t=(*p)->data;
		*p=NULL;
	}
	else
	{

		(*p)->next=temp->next;
		return temp->data;	
	}
	return t;
}
void display(node* p)
{
	node* temp;
	if(p==NULL)
	{
		printf("NULL\n");
		return;
	}
	temp=p->next;
	do
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}while(temp!=p->next);
}
void main()
{
	node *last;
	last=NULL;
	insert(&last,10);
	insert(&last,20);
	insert(&last,30);
	insert(&last,40);
	insert(&last,50);
	insert(&last,60);
	insert(&last,70);
	insert(&last,80);
	insert(&last,90);
	display(last);
	printf("Removing\n");
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	printf("%d\n",dequeue(&last));
	display(last);
	printf("After remove\n");
	insert(&last,10);
	insert(&last,20);
	insert(&last,30);
	insert(&last,40);
	insert(&last,50);
	insert(&last,60);
	display(last);
}
