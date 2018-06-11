/*
 ============================================================================
 Name        : hell.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int c=0;
typedef struct node
{
	int data;
	struct node*next;
}s;
int count(s *p)
{
	while(p!=NULL)
	{	++c;
	p=p->next;
	}

	return c;
}
int max(s *p)
{   int maxi;
	s *tem=p;
	maxi=tem->data;
while(p!=NULL)
  {
	if((p->data)>(tem->data))
		maxi=p->data;
	p=p->next;
}
return maxi;
}
 void add(s **p,int v)
{
	 s *new,*temp;
	new=(s*)malloc(sizeof(s));
	new->data=v;
	new->next=NULL;
	if(*p==NULL)
	{
		*p=new;
	}
	else
	{
		temp=*p;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}

}
 int ser(s *p,int x)
 {
	 int y=0;
	 while(p!=NULL)
	 {
		 if((p->data)==x)
			 y=1;
		 p=p->next;
	 }
	return y;
 }
/* void display(s *t)
 {
	 while(t!=NULL)
	 {
		 printf("%d\n",t->data);
		 t=t->next;
	}
 }*/
 void frees(s **t)
 {  s *te;
	 while((*t)!=NULL)
	 {
		 te=*t;
		 *t=(*t)->next;
		 free(te);
	 }
 }
int main(void) {
     int co,v,o;
	s *f=NULL;
	add(&f,10);
	add(&f,20);
	add(&f,30);
	add(&f,40);
	//display(f);
	co=count(f);
	printf("%d\n",co);
	v=max(f);
	printf("%d\n",v);
	o=ser(f,40);
	printf("%d",o);
	frees(&f);

	return 0;
}
