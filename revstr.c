#include<stdio.h>
#include<string.h>

void main()
{int ch,i,l,j,count;
  char s[100],str[100],c;
  while(1)
    {
      printf("\nEnter choice\n");
      scanf("%d",&ch);
      if(ch==4) break;
      printf("Enter string\n");
      __fpurge(stdin);
      gets(str);
      
      switch(ch)
	{
	case 1:for(l=0;str[l+1]!=0;l++);
	  j=0;
	  for(i=l;i>=0;i--)
	    {
	      s[j]=str[i];
	      j++;
	    }
	  s[j]=0;
	  printf("\nReversed string is\n");
	  puts(s);
	  break;
	
      
	case 2:printf("Entre element\n");
	  scanf("%d",&c);
	  count=0;
	  for(i=0;str[i]!=0;i++)
	    {
	      if(str[i]==c) count++;
	    }
pri


 
