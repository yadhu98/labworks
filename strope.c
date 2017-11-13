#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void strrev();
void strcate();
void palin();
void delsubstr();
void main()
{
	int ch;
	do
	{
		printf("\nMENU\n1)String Reversal\n2)String Concatination\n3)Check Palindrome\n4)delete a Substring\n5)Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: strrev();
				break;
			case 2: strcate();
				break;		
			case 3: palin();
				break;
			case 4: delsubstr();
				break;
			case 5:exit(0); 
			default:printf("invalid input");

		}

	}while(1);
}
void strrev()
{
	char str[100],strrev[100];
	int i,n=-1,j,k=0;
	printf("Enter the string");
	scanf("%s",&str);
	for(i=0;str[i]!="\0";i++)
	{
		n=n+1;
	}
	for(j=n;j>=0;j--)
	{
		strrev[k]=str[j];
		k=k+1;
	}
	printf("revesred string %s",strrev);
}
void palin()
{
	char str[100],strrev[100];
	int i,j=0,k,n=-1;
	printf("enter the string");
	scanf("%s",&str);
	for(i=0;str[i]!="\0";i++)
	{
		n=n+1;
	}
	for(k=n;k>=0;k--)
	{
		strrev[j]=str[k];
		j=j+1;
	}
	for(i=0,k=0;i<n,k<n;i++,k++)
	{
		if(str[i]==strrev[k])
		{
			printf("Pallindrome");
		}
		else
		{
			printf("Not pallindrome");
		}
	}
}
void  strcate()
{
	int i,j=0,n=0,k,l=0;
	char str1[100],str2[100],strfinl[200];
	printf("Enter 1st string");
	scanf("%s",&str1);
	printf("Enter 2st string");
	scanf("%s",&str2);
	for(i=0,j=0;str1[i]!="\0",j<=i;i++,j++)
	{
		strfinl[j]=str1[i];
		n=n+1;
	}
	for(k=0,j=n+1;str2[k]!="\0",j<=k;k++,j++)
	{
		strfinl[j]=str2[k];
		l=l+1;
	}
	strfinl[l+1]="\0";
	for(i=0;strfinl[i]!="\0";i++)
	{
		printf("%s",&strfinl);
	}
}
void delsubstr()
{
	char str[100],ele[10],str1[100];
	int i=0,l=0,j,k,flag=0;
	printf("enter a string");
	scanf("%s",&str);
	printf("enter the substring to be deleted");
	scanf("%s",&ele);
	while(str[i]!='\0')
	{
		if(str[i]=ele[0])
		{
			j=0;
			k=i;
			while(ele[j]!='\0')
			{
				if(ele[j]!=str[k])
				{
					flag=1;
					break;
				}
				else
				{
					k++;
					j++;
				}
			}
		}
		else
		{
			str1[l]=str[i];
			l++;
		}
		i++;
	}
		str1[l]=0;
	printf("%s",&str1);
}


