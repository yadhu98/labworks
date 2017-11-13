#include<stdio.h>

void main()
{
	int r,c,spar[10][3],i,j,nz=0,ele,mat[20][20];
	printf("\nEnter row and coloumn of the matrix\n");
	scanf("%d%d",&r,&c);
	spar[0][0]=r;spar[0][1]=c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nMAT[%d][%d]  ",i,j);
			scanf("%d",&ele);
			mat[i][j]=ele;
			if(ele!=0)
			{
				nz+=1;
				spar[nz][0]=i;
				spar[nz][1]=j;
				spar[nz][2]=ele;
			}
			
		}
	}
	spar[0][2]=nz;
	printf("\nMatrix is\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\nSparse matrix is\n");
	for(i=0;i<=nz;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d  ",spar[i][j]);
		}
		printf("\n");
	}
	
}

				
