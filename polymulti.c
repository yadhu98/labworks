#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coeff,exp;
	struct node *link;
}node;

node *start=NULL,*startr=NULL,*temp,*poly1,*poly2,*poly3;

node *createpoly();
int polymult();
int result(int,int);
int display();

void main()
{
	printf("\nCreate first polynomial\n");
	poly1=createpoly();
		
	printf("\nCreate second polynomial\n");
	poly2=createpoly();
	
	polymult();
	printf("\nProduct of two polynomials is\n");
	display();
}


node *createpoly()
{	
	start=NULL;
	int coeff,exp,n,i;
	printf("\nEnter no. of terms\n");
	scanf("%d",&n);
	i=1;
	while(i<=n)
	{
		node *p;
		p=(struct node*) malloc(sizeof(struct node));
		printf("\nEnter the exponent of term %d\n",i);
		scanf("%d",&exp);
		printf("\nEnter the coefficient of term %d\n",i);
		scanf("%d",&coeff);
		p->exp=exp;
		p->coeff=coeff;
		p->link=NULL;
		if(start==NULL) start=p;
		else
		{
			temp=start;
			while(temp->link!=NULL)
				temp=temp->link;
			temp->link=p;
		}
		i++;
	}
	return start;
}

int polymult()
{
	int c,e;
	while(poly1!=NULL)
	{
		temp=poly2;
		
		while(poly2!=NULL)
		{
			c=poly1->coeff * poly2->coeff;
			e=poly1->exp + poly2->exp;
		
			result(c,e);
			poly2=poly2->link;
		}
		poly1=poly1->link;
		poly2=temp;
	}
}
	

int result(int c,int e)
{
	node *p,*tempr,*temp1;
	int f=0;
	tempr=startr;
	while(tempr!=NULL)
	{
		if(tempr->exp==e)
		{
			tempr->coeff+=c;
			f=1;
			break;
		}
		else tempr=tempr->link;
		
	}
	if(f==0)
	{
		p=(node *) malloc(sizeof(node*));
		p->coeff=c;
		p->exp=e;
		p->link=NULL;
		if(startr==NULL)
		{
			startr=p;
			temp1=p;
		}
		else
		{
			temp1->link=p;
			temp1=p;
		}
		
	}
}

int display()
{
	node *tempr;
	tempr=startr;
	while(tempr!=NULL)
	{
		printf("%d x^%d ",tempr->coeff,tempr->exp);
		if(tempr->link!=NULL) printf(" + ");
		tempr=tempr->link;
	}
}		
			
		
			


