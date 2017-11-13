#include<stdio.h>

void main()
{
	int n,ar[20],i,j,pos,temp;
	printf("\nEnter size\n");
	scanf("%d",&n);
	printf("\nENter the elements in array\n");
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i;j<n;j++)
		{
			if(ar[pos]>ar[j]) pos=j;
			
		}
		if(pos!=i)
		{
			temp=ar[i];
			ar[i]=ar[pos];
			ar[pos]=temp;
		}
	}
	printf("\nSorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\n",ar[i]);
}
			
