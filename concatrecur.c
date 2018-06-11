#include<stdio.h>
char * add(char *fir,char *sec)
{
	char *ch,temp=0;
	ch=&temp;
	if(*fir==0&&*sec==0)
		return ch;
	else if(*fir==0)
	{
		*ch=*sec;
		sec=sec+1;
	}	
	else if(*sec==0)
	{
		*ch=*fir;
		fir=fir+1;
	}
	else
	{
		printf("Ek Barr Ghus Gaya\n");
		*ch=*fir;
		ch=ch+1;
		*ch=*sec;
		fir=fir+1;
		sec=sec+1;
	}
	ch=ch+1;
	strcat(ch,add(fir,sec));
	return ch;
}
void main()
{
	printf("Enter the 2 strings\n");
	char ch1[25],ch2[25];
	scanf("%s%s",ch1,ch2);
	char *ch3=add(ch1,ch2);
	strcat(ch3,"");
	printf("%s\n",ch3);
}
