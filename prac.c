#include<stdio.h>
#include<stdlib.h>
#define size 100


typedef struct que
{
	int datax[size],datay[size];
	int depth[size];
	int front,rear;
	int count;
}que;


void enqueue(que *q,int valx,int valy,int d)
{
	if(q->count<size)
	{
		q->datax[(q->rear+1)%size]=valx;
		q->datay[(q->rear+1)%size]=valy;
		q->count++;
		q->depth[q->rear=(q->rear+1)%size]=d+1;
	}
}


int isEmpty(que q)
{
	if(q.count==0)
		return 1;
	else
		return 0;
}

int* dequeue(que *q)
{
	int *t=(int *)malloc(sizeof(int)*3);
	if(!isEmpty(*q))
	{
		t[0]=q->datax[(q->front+1)%size];
		t[1]=q->datay[q->front=(q->front+1)%size];
		q->count--;
		return t;
	}
	else
	{
		return t[0]=-1;
	}
}

void main()
{
	printf("Enter  the order m*n\n");
	int m,n;
	scanf("%d%d",&m,&n);
	int i,j;
	int **mat(int **)malloc(sizeof(int *)*(m+2));
	printf("Enter m*n elememts\n");
	mat[0]=(int *)malloc(sizeof(int)*n);
	for(int j=0;j<n+2;j++)
	{
		mat[0][j]=0;
	}
	
	for(i=1;i<=m;i++)
	{
		mat[i]=(int *)malloc(sizeof(int)*(n+2));
		mat[i][0]=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
		mat[i][j]=0;
	}
	mat[i]=(int *)malloc(sizeof(int)*n);
	for(int j=0;j<n+2;j++)
	{
		mat[i][j]=0;
	}
	
	
	
	printf("Enter the start point x,y & end point x,y\n");
	int sx,sy,ex,ey;
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	
	shortestpath(mat,sx,sy,ex,ey,m,n);
}
int shortestpath(int **mat,int sx,int sy,int ex,int ey,int m,int n)
{
	int count=0;
	que q;
	q.front=-1;
	q.rear=-1;
	q.count=0;
	sx++;sy++;ex++;ey++;
	enqueue(&q,sx,sy);
	while(!isEmpty(q))
	{
		int *t=dequeue(&q);
		sx=t[0];sy=t[1];
		
		if(sx==ex&&sy==ey)
			return count;
		
	}
}