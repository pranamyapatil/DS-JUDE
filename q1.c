/*
 ============================================================================
 Name        : q.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#define max 5

typedef struct queue
{
	int data[max],front,rear;

}q;

int enqueue(q *a,int value)
{


	if(((a->rear+1)%max)==a->front)//empty
	{

		return 0;

	}
	else
	{
		a->rear=(a->rear+1)%max;

		a->data[(a->rear)]=value;
		return 1;
	}
}
int dequeue(q *a)
{
	if(a->rear==a->front)
	{
		return 0;

	}
	else


      a->front=(a->front +1)%max;

		return a->data[a->front];



}
void display(q *a)
{int i;
	for(i=(a->front+1)%max;i!=(a->rear+1)%max;i=(i+1)%max)
	{
		printf("%d\t",a->data[i]);
	}
}


int main() {

	q c;
	c.front=0;
	c.rear=0;
	enqueue(&c,10);

	enqueue(&c,20);
	enqueue(&c,30);
	enqueue(&c,40);
	//enqueue(&c,50);

	dequeue(&c);
	enqueue(&c,50);

	dequeue(&c);
	dequeue(&c);

	enqueue(&c,70);

	dequeue(&c);

	display(&c);

	return 0;
}
