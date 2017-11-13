#include<stdio.h>
int push(int);
int pop();
int dis();

int stack[20],pos=-1;
void main()
{
	int ch,n;
	printf("\nEnter the size\n");
	scanf("%d",&n);
	while(1)
	{
		printf("\nEnter choice\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
		scanf("%d",&ch);printf("\n");
		if(ch==4) break;
		else
		{
			switch(ch)
			{
				case 1:
				 push(n);
				break;
				
				case 2:
				pop();
				break;
				
				case 3:
				dis();
				break;
				
				default:printf("\nWrong choice\n");
				break;
			}
		}
	}
}

int push(int n)
{
	int ele;
	if(pos==n)
	{
		printf("\nStack overflow\n");
	
	}
	else
	{
		printf("\nEnter element to be inserted\n");
		scanf("%d",&ele);
		pos++;
		stack[pos]=ele;
		printf("\nElement inserted into stack\n");
		
	}
}

int pop()
{
	if(pos==-1) printf("\nStack underflow\n");
	else 
	{
		pos--;
		printf("\nElement deleted from top\n");
	}
}

int dis()
{	int i;
	if(pos==-1) printf("\nStack underflow\n");
	else
	{
		for(i=0;i<=pos;i++)
			printf("%d\n",stack[i]);
	}
}

	
	
			
