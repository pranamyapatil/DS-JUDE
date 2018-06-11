#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
}node;
void insertBST(node **p,int val)
{
    node *newnode,*temp;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if((*p)==NULL)
        (*p)=newnode;
    else
    {
        node *temp=*p;
        while(temp!=NULL)
        {
            //printf("Inserting %d and currently at %d\n",val,temp->data);
            if(temp->data>val&&temp->left!=NULL)
                temp=temp->left;
            else if(temp->data>val&&temp->left==NULL)
            {
                //printf("\n\nInserting %d to left of %d\n",val,temp->data);
                temp->left=newnode;
                break;
            }
            if(temp->right!=NULL&&temp->data<=val)
                temp=temp->right;
            else
            {
                //printf("\n\nInserting %d to right of %d\n",val,temp->data);
                temp->right=newnode;
                break;
            }
        }
    }
}
void display(node *p)
{
    if(p==NULL)
        return;
    else
    {
        display(p->left);
        printf("%d\n",p->data);
        display(p->right);
    }
}
int search(node *p,int val)
{
    while(p!=NULL)
    {
        if(p->data==val)
            return 1;
        else if(p->data>val)
            p=p->left;
        else
            p=p->right;
    }
    return 0;
}
int height(node *p)
{
    if(p==NULL)
        return 0;
    else
    {
        int x=height(p->left);
        int y=height(p->right);
        return x>y?x+1:y+1;
    }
}
void main()
{
    node *root;
    root=NULL;
    insertBST(&root,40);
    insertBST(&root,20);
    insertBST(&root,50);
    insertBST(&root,30);
    insertBST(&root,42);
    insertBST(&root,100);
    insertBST(&root,58);
    insertBST(&root,25);
    insertBST(&root,47);
    insertBST(&root,106);
    printf("\n\n\n");
    display(root);
    printf("\nThe value found's Truth Value is %d\nn",search(root,2006));
    printf("The Height of tree is %d\n",height(root));
}
