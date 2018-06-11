#include<stdio.h>
#define size 5
typedef struct queue 
{
	int data[size];
	int rear,front;
	int count;
}que;
int enqueue(que *q,int v)
{
	if(q->count<=size)	
	{
		q->data[q->rear=(++(q->rear))%size]=v;
		q->count++;
	}
 	else
		return 0;
	
	return 1;
}
int dequeue(que *q)
{
	if(q->count<=0)
	{
		return -1;
	}
	else
	{
		q->count--;
		return q->data[q->front=(++q->front)%size];
	}
}
void display(que q)
{
	while(q.count>0)
	{
		printf("%d\t%d\t%d\n",q.data[q.front=(q.front+1)%size],q.front,q.rear);
		q.count--;
	}
}
void main()
{
que q;
q.front=-1;
q.rear=-1;
q.count=0;
enqueue(&q,10);
enqueue(&q,20);
enqueue(&q,30);
enqueue(&q,40);
enqueue(&q,50);
display(q);
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
enqueue(&q,60);
enqueue(&q,70);
enqueue(&q,80);
dequeue(&q);
enqueue(&q,90);
enqueue(&q,100);

/*printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));
printf("POPPING\t%d\n",dequeue(&q));*/
display(q);
}
