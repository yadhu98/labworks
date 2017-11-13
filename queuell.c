#include<stdio.h>
#include<stdlib.h>

int push();
int pop();
int display();

struct node
{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL,*temp;
	
	
void main()
{
	int ch;
	while(1)
	{
		printf("\n\nEnter the choice\n1-Push\n2-Pop\n3-Display\n4-Exit\n");	
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
	printf("\nEnter the element\n");
	scanf("%d",&item);
	p->info=item;
	p->link=NULL;
	if(front==NULL && rear==NULL) front=p;
	else rear->link=p;
	rear=p;
}


int pop()
{
	if(front==NULL) printf("\nQueue is empty\n");
	else
	{
		temp=front;
		printf("\nDeleted element is %d\n",temp->info);
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
		}
		else front=front->link;
		free(temp);
	}
}

int display()
{
	if(front==NULL && rear==NULL) printf("\nQueue is empty\n");
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d -> ",temp->info);
			temp=temp->link;
		}
	}
}
