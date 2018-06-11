/*
 ============================================================================
 Name        : rts51.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : DELETE A NODE IN BINARY TREE.
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

NODE* searchBT(NODE *p,int val)
{
	if(p==NULL)
		return NULL;
	else if(p->left!=NULL && p->left->data==val)
		return p;
	else if(p->right!=NULL && p->right->data==val)
		return p;
	else
	{
		NODE *q;
		q=searchBT(p->left,val);
		if(q==NULL)
			q=searchBT(p->right,val);
		return q;
	}
}

int del(NODE **p,int val)
{
	NODE *temp,*prev=NULL;
	if((*p)!=NULL && (*p)->data==val)
		temp=*p;
	else
	{
		prev=searchBT((*p),val);
		if(prev==NULL)
			temp=NULL;
		else if(prev->left!=NULL && prev->left->data==val)
			temp=prev->left;
		else
			temp=prev->right;
	}

	if(temp==NULL)
		return 0;

	else
	{
		if(temp->left!=NULL && temp->right!=NULL)
		{
			NODE *succ=temp->right;
			prev=temp;
			while(succ->left!=NULL)
			{
				prev=succ;
				succ=succ->left;
			}
			temp->data=succ->data;
			if(prev->left==succ)
				prev->left=succ->right;
			else
				prev->right=succ->right;

			temp=succ;
		}

		else if(temp==*p)
		{
			if(temp->left!=NULL)
				*p=temp->left;
			else
				*p=temp->right;
		}

		else if(temp->left!=NULL && temp->right==NULL)
		{
			if(prev->left==temp)
				prev->left=temp->left;
			else
				prev->right=temp->left;
		}

		else if(temp->left==NULL && temp->right!=NULL)
			{
				if(prev->left==temp)
					prev->left=temp->right;
				else
					prev->right=temp->right;
			}

		else if(temp->left==NULL && temp->right==NULL)
			{
				if(prev->left==temp)
					prev->left=NULL;
				else
					prev->right=NULL;
			}
		free(temp);
		return 1;
	}
}

int main(void)
{
	NODE *root=NULL;
	insert(&root,50);
	insert(&root,25);
	insert(&root,70);
	insert(&root,10);
	insert(&root,40);
	insert(&root,15);
	insert(&root,12);
	insert(&root,60);
	insert(&root,90);
	insert(&root,80);
	insert(&root,55);
	insert(&root,57);
	inorder(root);
	del(&root,50);
	printf("\n");
	inorder(root);
}
