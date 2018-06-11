/*
 ============================================================================
 Name        : rts53.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : THREADED BINARY TREE.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int data;
	struct node *left;
	struct node *right;
	int LeftFlag;
	int RightFlag;
}NODE;

void insert(NODE **p,int val)
{
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=val;
	newnode->LeftFlag=0;
	newnode->RightFlag=0;

	if(*p==NULL)
	{
		*p=newnode;
		newnode->left=NULL;
		newnode->right=NULL;
	}
	else
	{
		NODE *temp=*p;
		while(1)
		{
			if(temp->data<val && temp->RightFlag)
				temp=temp->right;
			else if(temp->data>val && temp->LeftFlag)
				temp=temp->left;
			else
				 break;
		}

		if(temp->data<val)
		{
			newnode->right=temp->right;
			temp->right=newnode;
			temp->RightFlag=1;
			newnode->left=temp;
		}
		else
		{
			newnode->left=temp->left;
			temp->left=newnode;
			temp->LeftFlag=1;
			newnode->right=temp;
		}
	}
}

void inorder(NODE *p)
{
	while(1)
	{
		while(p->LeftFlag)
			p=p->left;
		printf("%d\t",p->data);
		while(!p->RightFlag)
		{
			p=p->right;
			if(p==NULL)
				return;
			printf("%d\t",p->data);
		}
		p=p->right;
	}
}

int main(void)
{
	NODE *root=NULL;
	insert(&root,50);
	insert(&root,75);
	insert(&root,60);
	insert(&root,70);
	insert(&root,25);
	insert(&root,55);
	inorder(root);


}
