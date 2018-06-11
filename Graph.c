/*
 ============================================================================
 Name        : rts48.c
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
    printf("%c\t",start+65);
	visited[start]=1;
	for(i=0;i<SIZE;i++)
	{
		if(a[start][i] && !visited[i]) //TO CHECK IF THAT NODE IS NOT VISITED
			dfs(a,visited,i);
	}
}

void bfs(int a[SIZE][SIZE],int visited[SIZE],int start)
{
	int queue[SIZE];
	int front=-1,rear=-1,i;
	for(i=0;i<SIZE;i++) //INITIALIZING VISITED TO 0.
		visited[i]=0;
	printf("%c\t",start+65);
	visited[start]=1;
	queue[++rear]=start;
	while(rear!=front)
	{
		start=queue[++front];
		for(i=0;i<SIZE;i++)
		{
			if(a[start][i] && !visited[i])
			{
				queue[++rear]=i;
				visited[i]=1;
				printf("%c\t",i+65);
			}
		}
	}
}

int main(void)
{
	int visited[SIZE]={0}; //TO KEEP TRACK IF THAT NODE IS VISITED OR NOT.
	int a[SIZE][SIZE]={{0}}; //INITIALIZING ENTIRE MATRIX TO O
	create_graph(a,1);
	dfs(a,visited,0); //0 stands for index of starting point
	printf("\n");
	bfs(a,visited,0);
	return 0;
}
