#include<stdio.h>

void main()
{
  int n,ar[20],ch,i,pos,ele,j,temp,flag;
  printf("Enter size of array\n");
  scanf("%d",&n);
  printf("\nEnter elements in array\n");
  for(i=0;i<n;i++)
  	scanf("%d",&ar[i]);
  while(1)
  {
  
  
  printf("Enter choice\n1-Insert\n2-Delete\n3-Traversal\n4-Sort\n5-Display\n6-Search\n7-Exit\n");
  scanf("%d",&ch);
  if(ch==7) break;
  else
  {
  switch(ch)
  {
  	case 1:
  	printf("\nEnter the position\n");
  	scanf("%d",&pos);
  	printf("\nEnter the element to be inserted\n");
  	scanf("%d",&ele);
  	for(i=n-1;i>=pos;i--)
  		ar[i+1]=ar[i];
  	n++;
  	ar[pos]=ele;
  	printf("\nModified array is\n");
  	for(i=0;i<n;i++)
  		printf("%d\n",ar[i]);
  	break;
  	
  	case 2:printf("\nEnter the element to be deleted\n");
  	scanf("%d",&ele);
  	for(i=0;i<n;i++)
  	{
  		if(ar[i]==ele)
  		{
  			for(j=i;j<n-1;j++)
  				ar[j]=ar[j+1];
  			n--;
  		}
  	}
  	printf("\nModified array is\n");
  	for(i=0;i<n;i++)
  		printf("%d\n",ar[i]);
  	break;
  	
  	case 3:for(i=0;i<n;i++)
  			printf("ar[%d] = %d\n",i,ar[i]);
  		break;
  		
  	case 4:for(i=0;i<n;i++)
  		{
  			for(j=0;j<n-i-1;j++)
  			{
  				if(ar[j]>ar[j+1])
  				{
  					temp=ar[j];
  					ar[j]=ar[j+1];
  					ar[j+1]=temp;
  				}
  			}
  		}
  		printf("\nSorted array is\n");
  		for(i=0;i<n;i++)
  			printf("%d\n",ar[i]);
  		break;
  		
  	case 5:printf("\nElements in array\n");
  		for(i=0;i<n;i++)
  			printf("%d\n",ar[i]);
  		break;
  	case 6:flag=0;
  	printf("\nEnter element to search\n");
  	scanf("%d",&ele);
  	for(i=0;i<n;i++)
  	{
  		if(ar[i]==ele) 
  		{printf("\nElement found in pos %d\n",i);flag=1;}
  		}
  	if(flag==0) printf("Element not found\n");
  	break;
  	
  	default:printf("\nWrong choice\n");
  	break;

}
}
  	
  		
  				
  			
  			
  	
  	
  		
  }
 }


