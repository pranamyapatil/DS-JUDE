/*
 ============================================================================
 Name        : rts47.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : BINARY TREE AND ITS OPERATIONS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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
		printf("Inserting %d\t Tree Trace :  ",val);
		NODE *newnode=(NODE*)malloc(sizeof(NODE));
		newnode->data=val;
		newnode->left=NULL;
		newnode->right=NULL;
		*p=newnode;
	}
	else
	{
		int ch;
		printf("Enter 1.Insert Left 2.Insert right : ");
		scanf("%d",&ch);
		if(ch==1)
			insert(&(*p)->left,val);
		else if(ch==2)
			insert(&(*p)->right,val);
	}
	printf("%d\t",(*p)->data); //TO DISPLAY TREE TRACE!
}

void preorder(NODE *p)
{
	if(p==NULL)
		return;
	else
	{
		printf("%d\t",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void postorder(NODE *p)
{
	if(p==NULL)
		return;
	else
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t",p->data);
	}
}

void inorder(NODE *p)
{
	if(p==NULL)
		return;
	else
	{
		inorder(p->left);
		printf("%d\t",p->data);
		inorder(p->right);
	}
}

int max(NODE *p)
{
	if(p==NULL)
		return 0;
	else
	{
		int m1,m2;
		m1=max(p->left);
		m2=max(p->right);
		if(p->data>m1 && p->data>m2)
			return p->data;
		else if(m1>m2)
			return m1;
		else
			return m2;

	}
}

int search(NODE *p,int val)
{
	if(p==NULL)
		return 0;

	else
	{
		if(p->data==val)
			return 1;
		else
			return search(p->left,val)||search(p->right,val);
	}
}

void mirror(NODE *p)
{
	if(p==NULL)
		return;
	else
	{
		NODE *temp;
		temp=p->right;
		p->right=p->left;
		p->left=temp;
		mirror(p->left);
		mirror(p->right);
	}
}

void copy(NODE **p,NODE *q)
{
	if(q==NULL)
		(*p)=NULL;
	else
	{
		*p=(NODE *)malloc(sizeof(NODE));
		(*p)->data=q->data;
		copy(&(*p)->left,q->left);
		copy(&(*p)->right,q->right);
	}
}

int complete(NODE *p)
{
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
	{
		int x=complete(p->left)+1;
		int y=complete(p->right)+1;
		if(x==y && x!=1)
			return x;
		else
			return 0;
	}
}

/* SIRS CODE-
int complete(NODE *p)
{
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
	{
		int x=complete(p->left);
		int y=complete(p->right);
		if(x==y && x!=0)
			return x+1;
		else
			return 0;
	}
}
*/

int main(void)
{
	int choice,value;
	NODE *root=NULL;
	NODE *root2=NULL;
	for(;;)
	{
		printf("\n1.Insert Value in Binary Tree.");
		printf("\n2.Display Binary Tree in Preorder.");
		printf("\n3.Display Binary Tree in Inorder.");
		printf("\n4.Display Binary Tree in Postorder.");
		printf("\n5.Find Max value in Binary Tree.");
		printf("\n6.Search for an element in Binary Tree.");
		printf("\n7.Mirroring a Binary Tree.");
		printf("\n8.To make a copy of a Binary Tree.");
		printf("\n9.To check if a Binary Tree is a Complete Binary Tree.");
		printf("\n10.Exit");
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("\nEnter Value to be Inserted : ");
				scanf("%d",&value);
				insert(&root,value);
				break;
		case 2: printf("\nBinary Tree in Preorder : ");
				preorder(root);
				break;
		case 3: printf("\nBinary Tree in Inorder : ");
				inorder(root);
				break;
		case 4: printf("\nBinary Tree in Postorder : ");
				postorder(root);
				break;
		case 5: value=max(root);
				printf("Maximum value = %d",value);
				break;
		case 6: printf("\nEnter Value to be Searched : ");
				scanf("%d",&value);
				value=search(root,value);
				if(value==0)
					printf("Value Not Found");
				else
					printf("Value Found");
				break;
		case 7: mirror(root);
				printf("Binary Tree Mirrored!");
				break;
		case 8: copy(&root2,root);
				printf("\nCopy Made!");
				break;
		case 9: value=complete(root);
				if(value==1)
					printf("Complete Binary Tree!");
				else
					printf("Not a Complete binary Tree!");
				break;
		case 10: exit(0);
				break;
		default: printf("Wrong Choice!");
		}
	printf("\n");
	}
}
