#include<stdio.h>
int push(int);
int pop(int);
int dis(int);

int cq[20],front=-1,rear=-1;

void main()
{
	int n,ch;
	printf("\nEnter the size\n");
	scanf("%d",&n);
	while(1)
	{

		printf("\nEnter choice\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\n");
		scanf("%d",&ch);
		if(ch==4) break;
		switch(ch)
		{
			case 1: push(n);
			break;
			case 2:pop(n);
			break;
			case 3:dis(n);
			break;
			default:printf("\nWrong choice\n");
			break;
		}
	}
}

int push(int n)
{
	int ele,pos;
	
	if(front==-1 && rear==-1)
	{	printf("\nEnter the element\n");
		scanf("%d",&ele);
		front=0;rear=0;
		cq[rear]=ele;
		dis(n);
	}
	else
	{	
		pos=(rear+1)%n;
		if(pos==front) printf("\nOverflow\n");
		else
		{	
			printf("\nEnter the element\n");
			scanf("%d",&ele);
			rear=pos;
			cq[rear]=ele;
			dis(n);
		}
	}
}

int pop(int n)
{
	int ele,pos;
	if(front==-1 && rear==-1) printf("\nUnderflow\n");
	else
	{
		ele=cq[front];
		if(front==rear)
		{
			front=-1;rear=-1;
		}
		else
		{
			front=(front+1)%n;
		}
		printf("\n%d deleted\n",ele);
		dis(n);
	}
}

			
int dis(int n)
{
	int i,j;
	if (front==-1 && rear==-1) printf("\nUnderflow\n");
	else
	{	printf("\nElements in queue :\n");
		if(rear<front)
		{
			for(i=front;i<n;i++)
				printf("%d\n",cq[i]);
			for(j=0;j<=rear;j++)
				printf("%d\n",cq[j]);
		}
		else
		{
			for(i=front;i<=rear;i++)
				printf("%d\n",cq[i]);
		}
				
	}
}
