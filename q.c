#include<stdio.h>
int push(int);
int pop();
int dis();

int q[20],front=-1,rear=-1;

void main()
{
	int n,ch;
	printf("\nEnter the size of array\n");
	scanf("%d",&n);
	while(1)
	{
		printf("\nEnter the choice\n1-PUSH\n2-POP\n3-DISPLAY\n4-EXIT\n");
		scanf("%d",&ch);
		if(ch==4) break;
		switch(ch)
		{
			case 1:push(n);
			break;
			case 2:pop();
			break;
			case 3:dis();
			break;
			default:printf("\nWrong choice\n");
			break;
		}
	}
}

int push(int n)
{	int ele;
	//printf("\nEnter the element\n");
	//scanf("%d",&ele);
	if(rear==n-1) printf("\nOverload\n");
	else if(front==-1 && rear==-1)
	{	printf("\nEnter the element\n");
	scanf("%d",&ele);
		front++;rear++;
		q[rear]=ele;
		dis();
	}
	else	
	{
		printf("\nEnter the element\n");
	scanf("%d",&ele);
		rear++;
		q[rear]=ele;
		dis();
	}
}


int pop()
{
	int ele;
	if (front==-1 && rear==-1) printf("\nUnderflow\n");
	else if(front==rear)
	{	
		ele=q[front];
		front=-1;rear=-1;
		printf("\nDeleted element is %d\n",ele);
		dis();
	}
	else
	{
		ele=q[rear];
		front++;
		printf("\nDeleted element is %d\n",ele);
		dis();
	}
	

}

int dis()
{	int i;
	if(front==-1 && rear==-1) printf("\nQueue is empty\n");
	else
	{
	
		printf("\n Queue is :\n");
		for(i=front;i<=rear;i++)
			printf("%d\n",q[i]);
	}
}
	
