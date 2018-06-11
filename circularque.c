/*
 ============================================================================
 Name        : rts25.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct queue
{
	int data[SIZE];
	int front;
	int rear;
	int count;
}QUEUE;

int enqueue(QUEUE *q,int value)
{

	if(q->count==SIZE)
		return 0;
	else
	{
	q->rear=(q->rear+1)%SIZE;
	q->data[q->rear]=value;
	q->count++;
    }
	return 1;
}

int dequeue(QUEUE *q)
{

	if(isEmpty(q))
	{
		printf("Cannot remove. Queue empty\n");
		return -22;
	}
		else
	{
		q->front=(q->front+1)%SIZE;
		q->count--;
		return q->data[q->front];
	}
}

int isEmpty(QUEUE *q)
{
	if(q->count==0)
	return 1;
	else
		return 0;
}

void display(QUEUE *q)
{
	int i;
	int c=q->count;
for(i=(q->front+1)%SIZE;c--;i=(i+1)%SIZE)
{
	printf("%d\n",q->data[i]);
}
}


int main(void) {
	QUEUE q;
	q.front=0;
	q.rear=0;
	q.count=0;
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	enqueue(&q,65);
	dequeue(&q);
	enqueue(&q,100);
	display(&q);
}

