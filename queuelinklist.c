#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	 int data;
	struct node* next;
}node;	
typedef struct queue
{
	node *rear,*front;
}que;
void insert(que *q,int val)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	if(q->rear==NULL)
	{
		q->rear=newnode;
		q->front=newnode;
	}
	else
	{
		q->rear->next=newnode;
		q->rear=newnode;
	}
}
int dequeue(que *q)
{
	int t;node *temp;
	if(q->front==NULL)
		return -1;
	if(q->front->next!=NULL)
	{
		temp=q->front;		
		t=q->front->data;
		q->front=q->front->next;
		free(temp);
	}
	else if(q->front->next==NULL)
	{
		t=q->front->data;
		q->front=NULL;
		q->rear=NULL;
	}
	return t;
}
void display(que q)
{
	while(q.front!=NULL)
	{
		printf("%d\n",q.front->data);
		q.front=q.front->next;
	}
}
void main()
{
	que q;
	q.front=NULL;
	q.rear=NULL;
	insert(&q,10);
	insert(&q,20);
	insert(&q,30);
	insert(&q,40);
	insert(&q,50);
	insert(&q,60);
	insert(&q,70);
	insert(&q,80);
	display(q);
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	printf("Removing:\t%d\n",dequeue(&q));
	display(q);
	printf("After remove\n");
	insert(&q,10);
	insert(&q,20);
	insert(&q,30);
	insert(&q,40);
	insert(&q,50);
	insert(&q,60);
	insert(&q,70);
	insert(&q,80);
	display(q);
}
