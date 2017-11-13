/*Replace a substring with a given string*/
#include<stdio.h>

void main()
{
char str[100], subrep[20], subtorep[20], temp;
int i, j, k, m, len, len1, len2, flag;
printf("\nEnter the string: ");
__fpurge(stdin);
gets(str);
printf("Enter the substring to be replaced: ");
gets(subtorep);
printf("Enter the substring to replace with: ");
__fpurge(stdin);
gets(subrep);
for(len=0; str[len]!='\0'; ++len);
for(len1=0; subtorep[len1]!='\0'; ++len1);
for(len2=0; subrep[len2]!='\0'; ++len2);
for(i=0; i<=len; ++i)
{
flag = 0;
k = 0;
if(str[i] == subtorep[k])
{
for(j=i; j<=i+len1-1; ++j)
{
if(str[j]==subtorep[k])
{
flag = 1;
++k;
}
else
{
flag = 0;
break;
}
}
}
if(flag == 1)
{
k=0;
while(k<len2)
{
if(k>=len1)
{
for(m = len+1; m>i-1; m--)
str[m] = str[m-1];
}
str[i] = subrep[k];
++k;
++i;
}
len = len + (len2-len1);
i = i - 1;
}
}
printf("The new string is: ");
puts(str);
}
