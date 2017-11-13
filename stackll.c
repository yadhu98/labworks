#include<stdio.h>
#include<stdlib.h>

int push();
int pop();
int display();

struct node
{
	int info;
	struct node *link;
}*top=NULL,*temp,*temp2;



void main()
{
	int ch;
	while(1)
	{
		printf("\nEnter choice\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
		scanf("%d",&ch);
		if(ch==4) break;
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			default:printf("\nWrong choice\n");
			break;
		}
	}
}


int push()
{
	int item;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the item\n");
	scanf("%d",&item);
	p->info=item;
	p->link=top;
	top=p;
}

int pop()
{
	if(top==NULL) printf("\nStack is empty\n");
	else
	{
		temp=top;
		printf("\nDeleted element is %d\n",top->info);
		top=top->link;
		free(temp);
	}
}


int display()
{
	temp=top;
	if(top==NULL) printf("\nStack is empty\n");
	else
	{

		while(temp!=NULL)
		{
			printf("%d -> ",temp->info);
			temp=temp->link;
		}
	
	}
}

		 
		
