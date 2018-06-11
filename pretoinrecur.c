#include<stdio.h>
#include<string.h>
char * pretoin(char *pre,char * in)
{
	char *p;
	if(*pre>='a'&&*pre<='z')
	{
		//char temp[2]="(";
		
		//strncat(in,temp,1);
		strncat(in,pre,1);
		return pre;
	}
	else
	{
		
		strncat(in,"(",1);
		p=pretoin(pre+1,in);
		strncat(in,pre,1);
		p=pretoin(p+1,in);
		strncat(in,")",1);
		return p;
	}
}
void main()
{
	char pre[20]="*+ab/cd";
	char infix[20]="";
	pretoin(pre,infix);
	printf("%s",infix);
}
