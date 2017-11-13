#include<stdio.h>
#include<stdlib.h>

int InsertBeg();
int InsertEnd();
int InsertAfterEle();
int InsertBeforeEle();
int DeleteBeg();
int DeleteEnd();
int DeleteBeforeEle();
int DeleteAfterEle();
int InsertPos();
int DeletePos();
int display();


struct node
{
	int info;
	struct node *right,*left;
}*start=NULL,*temp,*temp1;


void main()
{
	int ch;
	while(1)
	{
		printf("\nEnter the choice\n1-Insert at beginning\n2-Insert at end\n3-Insert after a specified element\n4-Insert before specified element\n5-Delete at beginning\n6-Delete from end\n7-Delete before an element\n8-Delete after an element\n9-Insert at specified position\n10-Deletion at specified position\n11-Display\n12-Exit\n");
		scanf("%d",&ch);
		if(ch==12) break;
		switch(ch)
		{
			case 1:InsertBeg();
			break;
			case 2:InsertEnd();
			break;
			case 3:InsertAfterEle();
			break;
			case 4:InsertBeforeEle();
			break;
			case 5:DeleteBeg();
			break;
			case 6:DeleteEnd();
			break;
			case 7:DeleteBeforeEle();
			break;
			case 8:DeleteAfterEle();
			break;
			case 9:InsertPos();
			break;
			case 10:DeletePos();
			break;
			case 11:display();
			break;
		}
	}
}

int InsertBeg()
{
	int item;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the item\n");
	scanf("%d",&item);
	p->info=item;
	p->right=NULL;
	p->left=NULL;
	if(start==NULL) start=p;
	else
	{
		p->right=start;
		p->left=NULL;
		start=p;
	}
}


int InsertEnd()
{
	
	int item;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the item\n");
	scanf("%d",&item);
	p->info=item;
	p->right=NULL;
	p->left=NULL;
	temp=start;
	if(start==NULL) start=p;
	else
	{
		while(temp->right!=NULL)
			temp=temp->right;
		temp->right=p;
		p->left=temp;
	}
}


int InsertAfterEle()
{
	int ele,item,f=1;
	temp=start;
	printf("\nEnter the element\n");
	scanf("%d",&ele);
	
	if(start==NULL) printf("\nEmpty list\n");
	else
	{
		while(temp->info!=ele)
		{
			if(temp->right==NULL)
			{
				printf("\nElement not found\n");
				f=0;break;
			}
			else temp=temp->right;
		}
	if(f==1)
	{
		struct node *p;
		p=(struct node*) malloc(sizeof(struct node));
		printf("\nEnter the item\n");
		scanf("%d",&item);
		p->info=item;
		p->left=temp;
		p->right=temp->right;
		
		if(temp->right!=NULL) temp->right->left=p;
		temp->right=p;
	}
	}
}

int InsertBeforeEle()
{
	int ele,item,f=1;
	temp=start;
	printf("\nEnter the element\n");
	scanf("%d",&ele);
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	
	if(start==NULL) printf("\nEmpty list\n");
	else if(temp->info==ele)
	{
		printf("\nEnter the item to be inserted\n");
		scanf("%d",&item);
		p->info=item;
		p->right=temp;
		p->left=NULL;
		temp->left=p;
		start=p;
	
	}
		
	else
	{
		while(temp->info!=ele)
		{
			if(temp->right==NULL)
			{
				printf("\nElement not found\n");
				f=0;break;
			}
			else temp=temp->right;
		}
		if(f==1)
		{
			
			printf("\nEnter the item\n");
			scanf("%d",&item);
			p->info=item;
			
			p->right=temp;
			if(temp->left!=NULL) temp->left->right=p;
			p->left=temp->left;
			temp->left=p;
	}
	}
}

int DeleteBeg()
{	
	int ele;
	if(start==NULL) printf("\nEmpty list\n");
	else
	{
		temp=start;
		if(temp->right==NULL) 
		{	
			ele=temp->info;
			start=NULL;
			free(temp);
			printf("\nElement deleted is %d\n",ele);
		}
		else
		{
			ele=temp->info;
			temp->right->left=NULL;
			start=temp->right;
			free(temp);
			printf("\nElement deleted is %d\n",ele);
		}
		
	}
}

int DeleteEnd()
{
	int ele;
	if(start==NULL) printf("\nEmpty list\n");
	else
	{
		temp=start;
		temp1=temp->right;
		while(temp1->right!=NULL)
		{
			temp=temp->right;
			temp1=temp1->right;
		}
		temp->right=NULL;
		ele=temp1->info;
		printf("\nElement deleted is %d\n",ele);
		free(temp1);
	}
}

int DeleteAfterEle()
{
	int ele,item,f=1;
	if(start==NULL) printf("\nEmpty List\n");
	else
	{	temp=start;
		printf("\nEnter the element\n");
		scanf("%d",&ele);
		while(temp->info!=ele)
		{
			if(temp->right==NULL)
			{
				f=0;
				printf("\nElement not found\n");
				break;
			}
			temp=temp->right;
		}
		if(f==1)
		{
			
			temp1=temp->right;item=temp1->info;
			temp->right=temp1->right;
			if(temp1->right!=NULL) temp1->right->left=temp;
			printf("\nElement deleted is %d\n",item);
			free(temp1);
		
		}
	}
}

int DeleteBeforeEle()
{
	int ele,item,f=1;
	if(start==NULL) 
		printf("\nEmpty list\n");
	else
	{
		temp=start;
		
		printf("\nEnter the element\n");
		scanf("%d",&ele);
		if(temp->info==ele) printf("\nNo data before specified element\n");
	
		else
		{
			while(temp->info!=ele)
			{
				if(temp->right==NULL)
				{
					f=0;
					printf("\nElement not found\n");
					break;
				}
				temp=temp->right;
			}	
			if(f==1)
			{

				temp1=temp->left;
				item=temp1->info;
				if(temp1->left!=NULL)
				{
					temp->left=temp1->left;
					temp->left->right=temp;
				}
				else 
				{	
					temp->left=NULL;
					start=temp;
				}
				free(temp1);				
				
				printf("\nElement deleted is %d\n",item);
		
			}
		}
	}
}
		
int InsertPos()
{
	int pos,f=1,ele,i;
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	printf("\nEnter the position\n");
	scanf("%d",&pos);
	
	if(pos==1) InsertBeg();
	
	else
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->right;
			if(temp==NULL)
			{
				f=0;
				printf("\nPosition not found\n");
				break;
			}
		}
		if(f==1)
		{
			printf("\nEnter the element\n");
			scanf("%d",&ele);
			p->info=ele;
			p->right=temp->right;
			p->left=temp;
			if(temp->right!=NULL) temp->right->left=p;
			temp->right=p;
		}
	}
}

int DeletePos()
{
	int pos,i,ele,f=1;
	printf("\nEnter the position\n");
	scanf("%d",&pos);
	if(pos==1) DeleteBeg();
	else
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->right;
			if(temp==NULL)
			{
				f=0;
				printf("\nPosition not found\n");
				break;
			}
		}
		if(f==1)
		{
			ele=temp->right->info;
			temp1=temp->right;
			temp->right=temp1->right;
			if(temp1->right!=NULL) temp1->right->left=temp;
			free(temp1);
			printf("\nDeleted element is %d\n",ele);
		}
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
			temp=temp->right;
		}
	}
}

	
	
		
		
	
	
	
	
	
