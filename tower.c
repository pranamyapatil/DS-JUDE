#include<stdio.h>
int tower(int n,char s,char a,char t)
{
	if(n==1)
	{	printf("Shift %d for %c to %c\n",n,s,t);
		return 1;}	
	else
	{	
		
	      int x=tower(n-1,s,t,a);
		printf("shift %d for %c to %c\n",n,s,t);
		int y=tower(n-1,a,s,t);
		return x+y+1;
	}
}
void main()
{
int n=4;
printf("\n\n%d\n",tower(n,'a','b','c'));
}
