/*
 ============================================================================
 Name        : link.c
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
 void frees(s **t)
  {  s *te;
 	 while((*t)!=NULL)
 	 {
 		 te=*t;
 		 *t=(*t)->next;
 		 free(te);
 	 }
  }
 void display(s *t)
  {
 	 while(t!=NULL)
 	 {
 		 printf("%d\n",t->data);
 		 t=t->next;
 	}
  }
/*void insert(s **p,int po,int v)
{  int i;
	s *new=(s*)malloc(sizeof(s));
	s *temp,*pos;
	temp=*p;




}*/
void insert(s **p,int v)
{
	s *temp,*first;
	first=*p;
	temp=*p;
	s *prev=*p;
	while(temp!=NULL)
	{
		if(temp->dar5ta>=v)
		break;
		prev=temp;
		temp=temp->next;		
	}
	s *var=(s *)malloc(sizeof(s));	
	var->data=v;
	if((*p)->data>v)
		*p=var;
	else
		prev->next=var;
	var->next=temp;
}
int main(void)
{
		s *f=NULL;
		add(&f,10);
		add(&f,20);
		add(&f,30);
		add(&f,40);
		insert(&f,49);
		display(f);
		frees(&f);
		return 0;
}

