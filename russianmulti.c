#include<stdio.h>
int multi(int no1,int no2)
{
	if(no1==0)
		return 0;
	else if(no1==1)
		return no2;
	else
	{
		if(no1%2==1)
			return no2+multi(no1/2,no2*2);
		else
			return multi(no1/2,no2*2);
	}
}
void main()
{
	printf("Enter 2 nos\n");
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	printf("%d\n",multi(n1,n2));
}
