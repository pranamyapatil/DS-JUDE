/*
 ============================================================================
 Name        : rts49.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : GRAPHS AND ITS TRAVERSAL.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 7

void create_graph(int a[][SIZE],int directed)
{
	int ch;
	do
	{
		char x,y;
		printf("Enter Source : ");
		scanf(" %c",&x);
		printf("Enter Destination : ");
		scanf(" %c",&y);
		a[x-65][y-65]=1;
		if(!directed)
			a[y-65][x-65]=1;
		printf("Press 1 to continue : "); //TO ADD MORE EDGES/RELATIONS
		scanf("%d",&ch);
	}while(ch==1);
}

void dfs(int a[SIZE][SIZE],int visited[SIZE],int start)
{
	int i;
	int stack[SIZE][2];
	int top=-1;
	printf("%c\t",start+65);
	visited[start]=1;
	stack[++top][0]=start;
	stack[top][1]=0;

	while(top!=-1)
	{
		start=stack[top][0];
		for(i=stack[top][1];i<SIZE;i++)
		{
			if(a[start][i] && !visited[i]) //TO CHECK IF THAT NODE IS NOT VISITED
			{
				stack[top][1]=i;
				stack[++top][0]=i;
				stack[top][1]=0;
				visited[i]=1;
				printf("%c\t",i+65);
				break;
			}
		}
		if(i==SIZE)
			top--;
	}
}

int main(void)
{
	int visited[SIZE]={0}; //TO KEEP TRACK IF THAT NODE IS VISITED OR NOT.
	int a[SIZE][SIZE]={{0}}; //INITIALIZING ENTIRE MATRIX TO O
	create_graph(a,1);
	dfs(a,visited,0); //0 is the index of the source or starting point.
	return 0;
}
