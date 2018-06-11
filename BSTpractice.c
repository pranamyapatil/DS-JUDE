#include<stdio.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;
int insertinTree(node **root,int val)
{
    if(*root==NULL)
    {
        node *newnode=(node *)malloc(sizeof(node));
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        *root=newnode;
        return 1;
    }
    else if((*root)->data>val)
        insertinTree(&(*root)->left,val);
    else
        insertinTree(&(*root)->right,val);
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}
int searchElement(node *root,int val)
{
    while(root!=NULL&&root->data!=val)
    {
        if(root->data>val)
            root=root->left;
        else
            root=root->right;
    }
    if(root==NULL)
    {
        printf("The Element is not Found..\nBetter Find somewhere else <><>>>\n");
        return 0;
    }
    else if(root->data==val)
    {
        printf("The Element is found.. \nHurrah!!\n\n");
        return 1;
    }
}
int getHeight(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lh=getHeight(root->left);
        int rh=getHeight(root->right);
        return lh>rh?lh+1:rh+1;
    }
}
int isFull(node * root)
{
    if(root==NULL)
        return 0;
    /*else if(root->left==NULL && root->right==NULL)
        return 1;*/
    else
    {
        int l=isFull(root->left);
        int r=isFull(root->right);
        printf("%d\t%d\n",r==l,root->data);
        return r==l;
    }
}
int isComplete(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lh=isComplete(root->left);
        int rh=isComplete(root->right);
        if(lh!=-1&&lh==rh)
            return lh+1;
        else
            return -1;
    }
}
int getDepth(node *root,node *targ)
{
    int count=0;
    while(root!=targ)
    {
        count++;
        if(root->data>targ->data)
            root=root->left;
        else
            root=root->right;
    }
    return count;
}
void getNodeatDepth(node *root,int d,int cd)
{
    if(root==NULL)
        return;
    else if(cd==d)
    {
        printf("%d\t",root->data);
    }
    else
    {
        getNodeatDepth(root->left,d,cd+1);
        getNodeatDepth(root->right,d,cd+1);
    }
}
void printinTreeFormat(node *root)
{
    int ht=getHeight(root);
    int count=0;
    while(count<=ht)
    {
        printf("\n");
        getNodeatDepth(root,count++,0);
    }
}
void main()
{
    int choice,temp;
    node *root=NULL;
    /*insertinTree(&root,10);
    insertinTree(&root,100);
    insertinTree(&root,30);
    insertinTree(&root,0);
    insertinTree(&root,50);
    insertinTree(&root,40);
    insertinTree(&root,70);
    insertinTree(&root,105);*/

    do{
        printf("Choose from the choices\n\n1:Insert in tree\n2:Inorder trvaersal of tree\n");
        printf("3:Searching for an element\n4:Get the height of the tree\n5:Check if the tree is Full(Strictly Binary Tree)\n");
        printf("6:Check if tree is Complete(isFull+leaves are at same height)\n7:Print in tree FFormat\n0:Exit!!\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value you wish to insert in tree\n");
            scanf("%d",&temp);
            insertinTree(&root,temp);
            break;
            case 2:printf("\n\n");inorder(root);break;
            case 3:printf("Enter the value to be searched\n");
            scanf("%d",&temp);
            searchElement(root,temp);break;
            case 4:printf("The height of the tree is : %d\n",getHeight(root)-1);break;
            case 5:printf("%d\n",isFull(root));break;
            case 6:printf("%d\n",isComplete(root));break;
            case 7:printinTreeFormat(root);break;
            case 0:break;
            default:printf("You have entered an invalid choice\n");
        }
    }while(choice!=0);
}


