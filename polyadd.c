#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coeff,exp;
	struct node *link;
}node;

node *start=NULL,*startr=NULL,*temp,*poly1,*poly2,*poly3;

node *createpoly();
int polyadd(node *,node *);
int result(int,int);
int display(node *);

void main()
{
	printf("\nCreate first polynomial\n");
	poly1=createpoly();
	
	printf("\nCreate second polynomial\n");
	poly2=createpoly();
	
	printf("\nFirst polynomial is\n");
	display(poly1);
	printf("\nSecond polynomial is\n");
	display(poly2);
	polyadd(poly1,poly2);
	printf("\nSum of two polynomials is\n");
	display(startr);
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

int polyadd(node *poly1,node *poly2)
{
	int s;
	node *p,*q;
	p=poly1;
	q=poly2;
	while(p!=NULL && q!=NULL)
	{
		if(p->exp==q->exp)
		{
			s=p->coeff+q->coeff;
			result(s,p->exp);
			p=p->link;
			q=q->link;
		}
		else if(p->exp > q->exp)
		{
			result(p->coeff,p->exp);
			p=p->link;
		}
		else
		{
			result(q->coeff,q->exp);
			q=q->link;
		}
	}
	while(p!=NULL)
	{
		result(p->coeff,p->exp);
		p=p->link;
	}
	while(q!=NULL)
	{
		result(q->coeff,q->exp);
			q=q->link;
	}
}


int result(int coeff,int exp)
{
	node *p;
	p=(struct node*) malloc(sizeof(struct node));
	p->exp=exp;
	p->coeff=coeff;
	p->link=NULL;
	if(startr==NULL) startr=p;
	else
	{
		temp=startr;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=p;
	}
}

int display(node *p)
{
	temp=p;
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->coeff,temp->exp);
		if(temp->link!=NULL) printf(" + ");
		temp=temp->link;
		
	}
	printf("\n");
}

		
		
		
		

	
