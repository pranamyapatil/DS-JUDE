#include<stdio.h>
#define size 5
typedef struct queue 
{
	int data[size];
	int rear,front;
}que;
int enqueue(que *q,int v)
{
	if((q->rear+1)%size!=(q->front=q->front%size))
	{
		q->data[q->rear=(++q->rear)%size];
		return 1;
	}
	else
		return 0;

}
int dequeue(que *q)
{
	if(q->rear==q->front)
	{
		return -1;
	}
	else
		return q->data[q->front=(++q->front)%size];
}
void display(que q)
{
	while(q.front<q.rear)
	{
		printf("%d\t%d\t%d\n",q.data[q.front=(++(q.front))%size],q.front,q.rear);
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
enqueue(&q,70);
enqueue(&q,80);
enqueue(&q,90);
enqueue(&q,150);
/*printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));*/
display(q);
}
