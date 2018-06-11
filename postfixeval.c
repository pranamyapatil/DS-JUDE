#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>

typedef struct _stack{
       char data[10];
        int top;
}stack;

int isempty(stack *p)
{
    if(p->top==-1)
       return 1;
    else
    	return 0;
}

void push(stack *p,char x){
   p->data[++(p->top)]=x;

}

void pop(stack *p){
   if(!isempty(p))
      p->top=p->top-1;
   else printf("Stack is empty");

}

int top(stack *p){
   return p->data[p->top];

}
int isDigit(char ch)
{
	if(ch>='0'&&ch<='9')
		return 1;
	else 
		return 0;
}

int main()
{  stack s;
  s.top=-1;
  int op1,op2;
   char a[10],ch;
    printf("Enter a valid postfix expression.\n");
     scanf("%s",a);
     int l =strlen(a),i;

    for(i=0;i<l;i++){
       ch=a[i];
       if(isDigit(ch)){
          push(&s,ch-'0');
         }
       else {
           op1=top(&s);pop(&s);
           op2=top(&s);pop(&s);
           switch(ch){

            case '+': push(&s,op2+op1);break;
            case '-':push(&s,op2-op1);break;
            case '/': push(&s,op2/op1);break;
            case '*':push(&s,op2*op1);break;
            }
            }
        }
        printf("Evaluation is %d\n",top(&s));


        return 0;


}
