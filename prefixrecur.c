#include<stdio.h>			//It Does'nt work as we cant access some memories
#include<string.h>
char * pretoin(char *pre,int *val,int *temp)
{
	printf("In Recur\n");
	char *p;
	if(*pre==-1)
	{
		*temp=*(pre+1);
		printf("In Solve %d\n",*temp);
		return pre+1;
	}
	if(*pre>='0'&&*pre<='9')
	{
		*temp=*pre-'0';
		printf("%d\n",*temp);
		return pre;
	}
	else
	{
		
		p=pretoin(pre+1,val,temp);
		p=pretoin(p+1,val,temp+1);
		switch(*pre)
		{
		case '+':*val=*temp+*(temp+1);break;
		case '-':*val=*temp-*(temp+1);break;
		case '*':*val=*temp**(temp+1);break;
		case '/':*val=*temp / *(temp+1);break;
		}
		*(p-1)=-1;
		*(p+1)=*val;
		printf("In Val\t%d\n",*val);
		p=p-1;
		return p;
	}
}
void main()
{
	char pre[20]="*-+5325";
	int *val,y,t,*temp;
	t=0;y=0;
	temp=&y;
	val=&t;
	pretoin(pre,val,temp);
	printf("%d\n",*val);
}
