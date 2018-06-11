#include<stdio.h>
int count(char *ch)
{
	if(*ch==0)
		return 0;
	else if(*ch>='a'&&*ch<='z')
		return count(&(*(ch+1)))+1;
}
void main()
{
	printf("Enter the String\n");
	char ch[100];
	gets(ch);
	printf("%d\n",count(ch));
}
		
