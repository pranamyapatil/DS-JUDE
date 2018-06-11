/*
 ============================================================================
 Name        : link.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>//Here if position not present then problem because in insert Null ->next is being inserted
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
void insert(s **p,int po,int v)
{
	int count=1;
	s *temp;
	temp=*p;
	s *nextp=*p;
	while(count<po-1&&temp!=NULL)
	{
		temp=temp->next;
		nextp=temp->next;
		count++;
	}
	if(temp==NULL)
	{
		printf("Fault");
		return;
	}
	s *var=(s *)malloc(sizeof(s));
	var->data=v;
	if(po==1)

		*p=var;
	else
		temp->next=var;
	var->next=nextp;
}
int main(void)
{
		s *f=NULL;
		add(&f,10);
		add(&f,20);
		add(&f,30);
		add(&f,40);
		insert(&f,2,49);
		display(f);
		frees(&f);
		return 0;
}

