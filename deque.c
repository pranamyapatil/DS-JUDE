#include<stdio.h>               //extra Removed
# define size 5
typedef struct que
{
        int front,rear,data[size];
}que;
int addFirst(que *p,int val)
{
        printf("In add f\n");
        if((p->front)-(p->rear)==1||(p->front)-(p->rear)==-1)
                return -1;
        else
        {
                if(p->front==-1&&p->rear==5)
                        p->rear=4;
                p->front=(++p->front)%size;
                p->data[p->front]=val;
                return 1;
        }
}
int addLast(que *p,int val)
{
        printf("In add l\n");
        if((p->front)-(p->rear)==1||(p->front)-(p->rear)==-1)
                return -1;
        else
        {
                if(p->rear==5&&p->front==-1)
                        p->front==0;
                p->rear=(p->rear-1)%size;
                if(p->rear<0)
                        p->rear+=size;
                p->data[p->rear]=val;
                return 1;
        }
}
int removeFirst(que *p)
{
        printf("In Remove\n");
        int temp;
        if(p->rear==p->front)
                return -1;
        else
        {  if(p->front<0)
                        p->front+=size;
                
                temp=p->data[p->front];
                p->front=(p->front-1)%size;
              
        }
        return temp;
}
int removeLast(que *p)
{

        int temp;
        if(p->rear==p->front)
                return -1;
        else
        {
                
                temp=p->data[p->rear];
                p->rear=(p->rear+1)%size;
        }
        return temp;
}
void main()
{
        que q;
        q.front=-1;
        q.rear=5;
        addFirst(&q,10);
        addFirst(&q,20);
        addFirst(&q,30);
        addFirst(&q,40);
        while(q.rear!=q.front)
        printf("%d\n",removeLast(&q));
        }
