#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
void insertBT(node **p,int v)
{
	printf("Inserting Value %d\n",v);
	if(*p==NULL)
	{
		node *newnode;
		newnode=(node *)malloc(sizeof(node));
		newnode->data=v;
		newnode->left=NULL;
		newnode->right=NULL;
		*p=newnode;
	}
	else
	{
		printf("Enter 1:If you want to enter on the right and 2:For Left of the value%d\n",(*p)->data);
		int ch;
		scanf("%d",&ch);
		if(ch==1)
			insertBT(&(*p)->left,v);
		else
			insertBT(&(*p)->right,v);
	}
}
int isDataBigger(int data,int v)
{
	printf("Comparing %d\t %d\n",data,v);
	if(data<v)
		return 0;
	else
		return 1;
}
int search(node *p,int val)
{
	if(p==NULL)
		return 0;
	printf("Searching with %d\n",p->data);
	if(p->data==val)
		return 1;
	else
	{
		if(search(p->left,val))
			return 1;
		else if(search(p->right,val))
			return 1;
		else return 0;
	}
}
int getHeight(node *p)
{
	if(p==NULL)
		return 0;
	else
	{
		int x=getHeight(p->left);
		int y=getHeight(p->right);
		return x+y+1;
	}
}
int isComplete(node *p)
{
	if(p==NULL)
		return 0;
	if(p->left==NULL&&p->right==NULL)
		return 1;
	else
	{
		int x,y;
		x=getHeight(p->left);
		y=getHeight(p->right);
		if(x==y)
		{
			return isComplete(p->left)&isComplete(p->right);
		else
			return 0;
	}
}
void toCopy(node *from,node **to)
{
	if(from==NULL)
	{
		*to=NULL;
		return;
	}	
	else
	{
		node *newnode;
		newnode=(node *)malloc(sizeof(node));
		newnode->data=from->data;
		(*to)=newnode;
		toCopy(from->left,&(*to)->left);
		toCopy(from->right,&(*to)->right);
	}
}		
void toMirror(node **p)
{
	if(*p==NULL)
		return; 
	node *temp;
	temp=(*p)->left;
	(*p)->left=(*p)->right;
	(*p)->right=temp;
	toMirror(&(*p)->left);
	toMirror(&(*p)->right);
}
void display(node *p)
{
	if(p==NULL)
		return;
	display(p->left);
	printf("%d  ",p->data);
	display(p->right);
}
void searchLargest(node *p,int *max)
{
	if(p==NULL)
		return;
	if(isDataBigger(p->data,*max))
		*max=p->data;
	//if(p->left!=NULL)
		searchLargest(p->left,max);
	//if(p->right!=NULL)
		searchLargest(p->right,max);
}
void main()
{
	node *root,*res;
	int max=0;
	root=NULL;
	res=NULL;
	insertBT(&root,50);
	insertBT(&root,70);
	insertBT(&root,90);
	insertBT(&root,25);
	insertBT(&root,60);
	insertBT(&root,110);
/*	searchLargest(root,&max);
	printf("The largest member in the tree is %d\n",max);
	search(root,35)?printf("\n\nThe value is Present\n"):printf("\n\nThe value is not present\n");
	printf("\n\n\n");
	display(root);
	toMirror(&root);
	printf("\n\n\n");
	display(root);
	toCopy(root,&res);
	printf("\n\nres\n");
	display(res);*/
	printf("%d\n",isComplete(root));
}
