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


	if(a->rear==max-1)     //full
	{

		return 0;

	}
	else
	{
		a->rear=a->rear+1;
		a->data[a->rear]=value;
		return 1;
	}
}
int dequeue(q *a)
{
	if(a->rear==a->front)          //empty
	{
		return 0;

	}
	else




		return a->data[++(a->front)];



}
void display(q a)
{int i;

	for(i=a.front+1;i<=a.rear;i++)
	{
		printf("%d\t",a.data[i]);
	}
}


int main() {

	q c;
	c.front=-1;
	c.rear=-1;
	enqueue(&c,10);
	enqueue(&c,20);
	enqueue(&c,30);
	enqueue(&c,40);
	enqueue(&c,50);
	dequeue(&c);
	dequeue(&c);
	dequeue(&c);
	dequeue(&c);

	display(c);

	return 0;
}
