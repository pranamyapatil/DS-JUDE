#include<stdlib.h>
#include<stdio.h>
typedef struct list
{
	int data;
	struct list *prev;
}list;
void push(list **p,int val)
{
	list *temp,*var,*newlist;
	temp=*p;
	newlist=(list *)malloc(sizeof(list));
	newlist->data=val;
	newlist->prev=NULL;
	if(*p==NULL)
	{
		*p=newlist;
	}
	else
	{
		newlist->prev=temp;
		(*p)=newlist;
	}
}
int pop(list **p)
{
	list *temp;
	if(*p!=NULL)
	{
		temp=(*p);
		(*p)=(*p)->prev;
		return temp->data;
	}
	else
	return -1;
}
int peak(list *p)
{
	return p->data;
}
int isEmpty(list *p)
{
	 if((p)==NULL)
	return 1;
	else
	return 0;
}
void main()
{
	list *last;
	last=NULL;
	push(&last,1);
	push(&last,2);
	push(&last,3);
	push(&last,4);
	push(&last,5);
	push(&last,6);
	push(&last,7);
	printf("%d\n",pop(&last));
	printf("%d\n",peak(last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
	printf("%d\n",pop(&last));
}
