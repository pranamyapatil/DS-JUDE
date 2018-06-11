#include<stdio.h>
#include<string.h>
char* count(int n)
{
	char ch[100];			//stack might be dumped as char array big memory is required*/
	ch[0]=0;
	char t0='0';
	char t1='1';
	if(n==0)
		return &t0;
	else if(n==1)
		return &t1;
	else
	{
		int t=n;
		strcat(ch,count(n/2));
		strcat(ch,t%2);
		return ch;
	}
}
void main()
{
	printf("Enter the no.\n");
	int no;
	scanf("%d",&no);
	char *ch=count(no);
	*(ch+1)=0;
	printf("%s\n",ch);
}
