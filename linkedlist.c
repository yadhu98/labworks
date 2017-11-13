#include<stdio.h>
#include<stdlib.h>
int pushf();
int popf();
int pushr();
int popr();
int pushp();
int popp();
int display();

struct node
{
	int info;
	struct node *link;
}*temp,*start=NULL,*temp2;


void main()	
{
	int ch;
	while(1)
	{
		printf("\n\nEnter the choice\n1-Push at front\n2-Pop at front\n3-Push at end\n4-Pop at end\n5Push at any pos\n6-Pop at any position\n7-Dispaly\n8-Exit\n");
		scanf("%d",&ch);
		if(ch==8) break;
		switch(ch)
		{
			case 1:pushf();
			break;
			case 2:popf();
			break;
			case 3:pushr();
			break;
			case 4:popr();
			break;
			case 5:pushp();
			break;
			case 6:popp();
			break;
			case 7:display();
			break;
			default:printf("\nWrong choice\n");
			break;
		}
	}

}

int pushf()
{
	int item;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the element\n");
	scanf("%d",&item);
	p->info=item;
	p->link=NULL;
	if(start==NULL) start=p;
	else
	{
		p->link=start;
		start=p;
	}
}

int popf()
{
	temp=start;temp2=start;
	if(start==NULL) printf("\nStack is empty\n");
	else
	{	
		temp=temp->link;
		free(temp2);
		start=temp;
		printf("\nItem deleted from front\n");
	}
}

int pushr()
{
	int item;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter th element \n");
	scanf("%d",&item);
	p->info=item;
	p->link=NULL;
	if(start==NULL) start=p;
	else
	{
		temp=start;
		while(temp->link!=NULL)
			temp=temp->link;	
		temp->link=p;
	}
}

int popr()
{
	if(start==NULL) printf("\nStack is empty\n");

	else
	{
		temp=start;
		if(temp->link==NULL)
		{
			start=NULL;
			free(temp);
		}
		else
		{
		temp2=temp->link;
		while(temp2->link!=NULL)
			{temp2=temp2->link;
			temp=temp->link;
			}
		printf("\nDeleted element is %d\n",temp2->info);
		temp->link=NULL;
		free(temp2);
		}
	
	}
}

int pushp()
{
	int item,pos,i;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the position\n");
	scanf("%d",&pos);
	printf("\nEnter the item\n");
	scanf("%d",&item);
	p->info=item;
	p->link=NULL;
	if(pos==1)
	{
		p->link=start;
		start=p;
	}
	else
	{	
		temp=start;
		for(i=1;i<pos-1;i++)
			temp=temp->link;
		p->link=temp->link;
		temp->link=p;
	}
}


int popp()
{
	int pos,i;
	if(start==NULL) printf("\nList is empty\n");
	else
	{	temp=start;temp2=temp->link;
		printf("\nEnter the position\n");
		scanf("%d",&pos);
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
			temp2=temp2->link;
		}
		printf("\nDeleted element is %d\n",temp2->info);
		temp->link=temp2->link;
		free(temp2);
	}
}


int display()
{
	if(start==NULL) printf("\nEmpty list\n");
	else
	{	temp=start;
		printf("\n");
		while(temp!=NULL)
		{
			printf("%d -> ",temp->info);
			temp=temp->link;
		}
	}
}

		
			
		
