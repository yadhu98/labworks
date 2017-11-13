#include<stdio.h>
#include<string.h>

int len(char[]);
int conca(char[],char[]);
int comp(char[],char[]);
int copy(char[],int);

void main()
{
  char str1[50],str2[50];
  int l1,l2,n;
  printf("Enter string 1\n");
  __fpurge(stdin);
  gets(str1);
  printf("Enter string 2\n");
  __fpurge(stdin);
  gets(str2);
  l1=len(str1);
  printf("Length of first string is %d\n",l1);
  l2=len(str2);
  printf("Length of second string is %d\n",l2);
  conca(str1,str2);
  
  if(l1!=l2) printf("\nBoth string are unequal\n");
  else
    {
      n=comp(str1,str2);
      if(n==0) printf("\nBoth strings are equal\n");
      else printf("\nBoth strings are unequal\n");
    }
  printf("\nstring copy\n");
  printf("\nFirst strig\n");
  copy(str1,l1); 
  printf("\nSecond string\n");
  copy(str2,l2);
}

int len(char str[50])
{
  int l;
  for(l=0;str[l]!=0;l++);
  return l;
}

int conca(char s1[50],char s2[50])
{
  int i,j;
  char str[100];
  for(i=0;s1[i]!=0;i++)
      str[i]=s1[i];
  for(j=0;s2[j]!=0;j++)
    {
      str[i]=s2[j];
      i++;
    }
  str[i]=0;
  printf("\nConcatenated string is\n");
   puts(str);
  return 0;
}

int comp(char s1[50],char s2[50])
{
  int i,j;
  for(i=0;s1[i]!=0;i++)
    {
      if(s1[i]!=s2[i]) return -1;
      else
	continue;
    }
  return 0; 
}

int copy(char s[50],int l)
{
  int i,j,l1;
  char str[50];
  printf("\nEnter new string\n");
  __fpurge(stdin);
  gets(str);
  for(i=0;str[i]!=0;i++)
    s[i]=str[i];
  s[i]=0;
  printf("\nString is \n");
  puts(s);
  return 0;
}


