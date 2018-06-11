/*
 ============================================================================
 Name        : rts52.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : BINARY SEARCH TREE OPERATIONS (WITHOUT RECURSION)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

void insert(NODE **p,int val)
{
	if(*p==NULL)
	{
		printf("Insert Succesful.");
		NODE *newnode=(NODE*)malloc(sizeof(NODE));
		newnode->data=val;
		newnode->left=NULL;
		newnode->right=NULL;
		*p=newnode;
	}
	else if((*p)->data>val)
		insert(&(*p)->left,val);
	else
		insert(&(*p)->right,val);
	//printf("%d\t",(*p)->data); //TO DISPLAY TREE TRACE!
}

void preorder(NODE *p)
{
	NODE *s[SIZE];
	int top=-1;
	while(1)
	{
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			s[++top]=p;
			p=p->left;
		}

		if(top!=-1)
		{
			p=s[top--];
			p=p->right;
		}

		else
			break;
	}
}

void inorder(NODE *p)
{
	NODE *s[SIZE];
	int top=-1;

	while(1)
	{
		while(p!=NULL)
		{
			s[++top]=p;
			p=p->left;
		}

		if(top!=-1)
		{
			p=s[top--];
			printf("%d\t",p->data);
			p=p->right;
		}
		else
			break;
	}
}

void postorder(NODE *p)
{
	NODE *s[SIZE];
	int flag[SIZE];
	int top=-1;

	while(1)
	{
		while(p!=NULL)
		{
			s[++top]=p;
			flag[top]=0;
			p=p->left;
		}

		while(top!=-1 && flag[top]==1)
		{
			p=s[top--];
			printf("%d\t",p->data);
		}

		if(top!=-1)
		{
			p=s[top];
			p=p->right;
			flag[top]=1;
		}

		else
			break;
	}
}

int main(void)
{
	int choice,value;
	NODE *root=NULL;
	for(;;)
	{
		printf("\n1.Insert Value in Binary Search Tree.");
		printf("\n2.Display Binary Search Tree in Preorder.");
		printf("\n3.Display Binary Search Tree in Inorder.");
		printf("\n4.Display Binary Search Tree in Postorder.");
		printf("\n5.Exit");
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter Value to be Inserted : ");
					scanf("%d",&value);
					insert(&root,value);
					break;
			case 2: printf("Binary Search Tree in Preorder : ");
					preorder(root);
					break;
			case 3: printf("Binary Search Tree in Inorder : ");
					inorder(root);
					break;
			case 4: printf("Binary Search Tree in Postorder : ");
					postorder(root);
					break;
			case 5: exit(0);
			default: printf("\nWrong choice!");
		}
		printf("\n");
	}
}
