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
	int data[max],front,rear,count;

}q;

int enqueue(q *a,int value)
{


	if(a->count==max)//full
	{

		return 0;

	}
	else
	{
		a->rear=(a->rear+1)%max;

		a->data[(a->rear)]=value;
		a->count++;
		return 1;
	}
}
int dequeue(q *a)
{
	if(a->count==0)  //empty
	{
		return 0;

	}
	else


      a->front=(a->front +1)%max;

	    a->count--;
		return a->data[a->front];



}
void display(q *a)
{int i,c;
c=a->count;
	for(i=(a->front+1)%max;c-->0;i=(i+1)%max)
	{
		printf("%d\t",a->data[i]);
	}
}



int main() {

	q c;
	c.front=0;
	c.rear=0;
	c.count=0;
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
	enqueue(&c,80);

	display(&c);

	return 0;
}
