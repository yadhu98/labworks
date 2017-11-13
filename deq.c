#include<stdio.h>

int pushf(int);
int pushr(int);
int popf(int);
int popr(int);
int dis(int);

int dq[20],rear=-1,front=-1;

void main()
{
	int n,ch;
	printf("\nEnter size\n");
	scanf("%d",&n);
	while(1)
	{
		printf("\nEnter choice\n1-Insertion at front\n2-Insertion at rear\n3-Deletion at front\n4-Deletion at rear\n5-Display\n6-Exit\n");
		scanf("%d",&ch);
		if(ch==6) break;
		switch(ch)
		{
			case 1:pushf(n);
			break;
			case 2:pushr(n);
			break;
			case 3:popf(n);
			break;
			case 4:popr(n);
			break;
			case 5: dis(n);
			break;
			default:printf("\nWrong choice\n");
			break;
		}
	}
}

int pushf(int n)
{
	int ele,pos;
	if(front==-1 && rear==-1) 
	{
		front=0;rear=0;
		printf("\nEnter the elelment\n");
		scanf("%d",&ele);
		dq[front]=ele;
		dis(n);
	}
	else
	{
	if(front==0) pos=n-1;
	else pos=front-1;
	if (pos==rear) printf("\nOverload\n");
	else
	{	printf("\nEnter the element\n");
		scanf("%d",&ele);
		front=pos;
		dq[front]=ele;
		dis(n);
	}
	}
}


int pushr(int n)
{
	int pos,ele;
	if(front==-1 && rear==-1)
	{	printf("\nEnter the element\n");
		scanf("%d",&ele);
		front=0;rear=0;
		dq[rear]=ele;
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
			dq[rear]=ele;
			dis(n);
		}
	}
}

int popf(int n)
{
	int ele,pos;
	if(front==-1 && rear==-1) printf("\nUnderflow\n");
	else
	{
		ele=dq[front];
		if(front==rear)
		{
			front==-1;rear==-1;
		}
		else
		{
			front=(front+1)%n;
		}
		printf("\n%d deleted\n",ele);
		dis(n);
	}
}

int popr(int n)
{	int ele;
	if(front==-1 && rear==-1) printf("\nUnderflow\n");
	else if(front==rear)
	{
		ele=dq[rear];
		rear=-1;front=-1;
		printf("\n%d deleted\n",ele);
		dis(n);
	}
	else if(rear==0)
	{
		ele=dq[rear];
		rear=n-1;
		printf("\n%d deleted\n",ele);
		dis(n);
	}
	else
	{
		ele=dq[rear];
		rear=rear-1;
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
				printf("%d\n",dq[i]);
			for(j=0;j<=rear;j++)
				printf("%d\n",dq[j]);
		}
		else
		{
			for(i=front;i<=rear;i++)
				printf("%d\n",dq[i]);
		}
		
				
	}
}		

