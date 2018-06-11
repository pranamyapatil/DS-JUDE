#include<stdio.h>
#define size 25
typedef struct queue 
{
	int data[size];
	int rear,front;
	int count;
}que;
int enqueue(que *q,int v)
{
	if(q->rear<size-1)	
		q->data[++(q->rear)]=v;
 	else if(count==size)
		return 0;
	
	return 1;
}
int dequeue(que *q)
{
	if(q->rear==q->front)
	{
		return -1;
	}
	else
		return q->data[++q->front];
}
void display(que q)
{
	while(q.front<q.rear)
	{
		printf("%d\t%d\t%d\n",q.data[++(q.front)],q.front,q.rear);
	}
}
void main()
{
que q;
q.front=-1;
q.rear=-1;
enqueue(&q,10);
enqueue(&q,20);
enqueue(&q,30);
enqueue(&q,40);
enqueue(&q,50);
display(q);
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
enqueue(&q,60);
/*printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));*/
display(q);
}
