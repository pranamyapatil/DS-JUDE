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
node * common(node *f,node *s)
{
	node *var=s;
	node *temp=(node *)malloc(sizeof(node));
	for(;f!=NULL;f=f->next)
	{
		var=s;
		for(;var!=NULL;var=var->next)
		{
			if(f->data==var->data)
			{
				add(&temp,f->data);
				break;
			}
		}
	}
return temp;
}
void main()
{
node *fir=NULL,*sec=NULL;
add(&fir,9);
add(&sec,9);
add(&fir,2);
add(&sec,2);
add(&fir,3);
add(&sec,4);
add(&fir,5);
add(&sec,4);
add(&fir,6);
add(&sec,7);
add(&fir,2);
add(&sec,6);
add(&fir,8);
add(&sec,8);
node *var=common(fir,sec);
display(var);
}
