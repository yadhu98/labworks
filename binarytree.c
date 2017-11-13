#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *lc,*rc;
}node;

node *root=NULL,*parent,*temp;

int Insert();
int Delete(int);
int Search();
node *Inorder(node *);
int Preorder(node *);
int Postorder(node *);
node *Succ(node*);


void main()
{
	int ch,t,ele;
	while(1)
	{
		printf("\nEnter choice\n  1-Insertion\n  2-Deletion\n  3-Search\n  4-Traversal\n  5-Exit\n");
		scanf("%d",&ch);
		if(ch==5) break;
		switch(ch)
		{
			case 1:Insert();
			 break;
			case 2:printf("\nEnter the element\n");
			scanf("%d",&ele);Delete(ele);
			 break;
			case 3:Search();
			 break;
			case 4:printf("\n1-Inorder\n2-Preorder\n3-Postorder\n");
			 scanf("%d",&t);
			 switch(t)
			 {
			 	case 1:Inorder(root);
			 	 break;
			 	case 2:Preorder(root);
			 	 break;
			 	case 3:Postorder(root);
			 	 break;
			 	default:printf("\nWrong choice\n");
			 	 break;
			 }
			 break;
			default:printf("\nWrong choice\n");
			 break;
		}
	}
	
}

int Insert()
{
	int ele;
	node *ptr;
	ptr=root;
	ptr=(node *) malloc(sizeof(node));
	printf("\nEnter the element\n");
	scanf("%d",&ele);
	ptr->info=ele;
	printf("%d",ptr->info);
	ptr->lc=NULL;
	ptr->rc=NULL;
	if(root==NULL)
	{
	 root=ptr;
	// printf("%d",ptr->info);
	}
	else
	{
		while(ptr!=NULL)
		{
			parent=ptr;
			if(ele < ptr->info) ptr=ptr->lc;
			else ptr=ptr->rc;
		}
		if(ele < parent->info) parent->lc = ptr;
		else parent->rc = ptr;
	
	}
}

int Search()
{
	int ele,f=0;
	printf("\nEnter the element to search\n");
	scanf("%d",&ele);
	temp=root;
	while(temp!=NULL && f==0)
	{
		if(ele < temp->info) temp = temp->lc;
		else if(temp->info == ele) f=1;
		else temp = temp->rc;
	}
	if(f==1) printf("\nSearched element found in tree\n");
	else printf("\nSearched element not found\n");
}

int Delete(int ele)
{
	node *ptr;
	ptr=root;
	int f=0;

	while(ptr!=NULL && f==0)
	{
		if(ele < ptr->info) 
		{
			parent=ptr;
			ptr = ptr->lc;
		}		
		else if(ptr->info == ele) f=1;
		else
		{
			parent=ptr;
			ptr = ptr->rc;
		}
	}
	if(f==0) printf("\nNot found\n");
	else
	{
		if(ptr->lc == NULL && ptr->rc == NULL)
		{
			if(parent->lc == ptr) 
				parent->lc=NULL;
			else
				parent->rc=NULL;
			free(ptr);
		}
		
		else if(ptr->rc!=NULL && ptr->lc!=NULL)
		{
			node *ptr1;
			ptr1=Succ(ptr);
			ele=ptr1->info;
			Delete(ptr1->info);
			ptr->info=ele;
			free(ptr1);		
		}
		
		else
		{
			if(parent->lc==ptr)
			{
				if(ptr->lc==NULL)
					parent->lc=ptr->rc;
				else
					parent->lc=ptr->lc;
			}
			else if(parent->rc==ptr)
			{
				if(ptr->lc==NULL)
					parent->rc=ptr->rc;
				else
					parent->rc=ptr->lc;
			}
			free(ptr);
		}
	}
}

node* Inorder(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		Inorder(temp->lc);
		printf("%d  ",temp->info);
		Inorder(temp->rc);
	}
}

int Preorder(node *root)
{
	temp=root;
	if(temp!=NULL)
	{
		printf("%d  ",temp->info);
		Preorder(temp->lc);
		Preorder(temp->rc);
	}
}

int Postorder(node *parent)
{
	node *temp=parent;
	if(temp!=NULL)
	{
		Postorder(temp->lc);
		Postorder(temp->rc);
		printf("%d  ",temp->info);
	}
}

node *Succ(node *parent)
{
	node *ptr;
	ptr=parent->rc;
	if(ptr!=NULL)
		while(ptr->lc!=NULL)
			ptr=ptr->lc;
	return(ptr);
}
	
	
	
