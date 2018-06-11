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
node * union1(node *f,node *s)
{
	int flag=0;
	node *temp=(node *)malloc(sizeof(node));
	node *var=s;
	for(;f!=NULL;f=f->next)
	{
		flag=0;
		for(var=s;var!=NULL;var=var->next)
		{
			if(var->data==f->data)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		add(&temp,f->data);
	}
	while(s!=NULL)
	{
		add(&temp,s->data);
		s=s->next;
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
node *var=union1(fir,sec);
display(var);
}
