/*
 ============================================================================
 Name        : rts46.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : BINARY SEARCH TREE AND ITS OPERATIONS
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

int count(NODE *p)
{
	int x,y;
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
	{
		x=count(p->left);
		y=count(p->right);
		return x+y+1;
	}
}


int search(NODE *p,int value)
{
	int flag=0;
	if(p==NULL)
		return 0;
	else
	{
		if(p->data==value)
			return 1;
		else if(p->data>value)
			flag=search(p->left,value);
		else
			flag=search(p->right,value);
		return flag;
	}
}

int search_iterate(NODE *p,int value)			//More Preferable of Sir
{
	do
	{
		if(p==NULL)
			return 0;
		else
		{
			if(p->data==value)
				return 1;
			else if(p->data>value)
				p=p->left;
			else
				p=p->right;
		}
	}while(p!=NULL);
	return 0;
}

int count_leaf(NODE *p)
{
	int count;
	if(p==NULL)
		return 0;
	if(p->left==NULL && p->right==NULL)
		return 1;
	else
	{
		count=count_leaf(p->left)+count_leaf(p->right);
		return count;
	}
}

int height(NODE *p)
{
	int x,y;
	if(p==NULL ||(p->left==NULL && p->right==NULL))
		return 0;
	else
	{
		x=height(p->left);
		y=height(p->right);
		if(x>y)
			return x+1;
		else
			return y+1;
	}

}

int full(NODE *p)
{
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
	{
		if(full(p->left) && full(p->right))
			return 1;
		else
			return 0;
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
		printf("\n5.Count number of nodes in Binary Search Tree.");
		printf("\n6.Search for an element in Binary Search Tree.");
		printf("\n7.Count the number of leaf nodes in Binary Search Tree.");
		printf("\n8.Calculate the height of Binary Search Tree.");
		printf("\n9.Check if it is a Full Tree.");
		printf("\n10.Exit");
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("\nEnter Value to be Inserted : ");
				scanf("%d",&value);
				insert(&root,value);
				break;
		case 2: printf("\nBinary Search Tree in Preorder : ");
				preorder(root);
				break;
		case 3: printf("\nBinary Search Tree in Inorder : ");
				inorder(root);
				break;
		case 4: printf("\nBinary Search Tree in Postorder : ");
				postorder(root);
				break;
		case 5: value=count(root);
				printf("Number of Nodes = %d",value);
				break;
		case 6: printf("\nEnter Value to be Searched : ");
				scanf("%d",&value);
				value=search_iterate(root,value);  //OR SERACH USING RECURSION
				if(value==0)
					printf("Value Not Found");
				else
					printf("Value Found");
				break;
		case 7: value=count_leaf(root);
				printf("Number of Leaf Nodes = %d",value);
				break;
		case 8: value=height(root);
				printf("Height of Binary Search Tree = %d",value);
				break;
		case 9: value=full(root);
				if(value==1)
					printf("Full Tree");
				else
					printf("Not a Full Tree");
				break;
		case 10: exit(0);
				break;
		default: printf("Wrong Choice!");
		}
	}
}
