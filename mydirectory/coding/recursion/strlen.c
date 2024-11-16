#include <stdio.h>
#include<string.h>
//int strlen(int a[])
int main()
{
   char arr[50];
   int count=0;
   int i=0;
   gets(arr);
   //printf("%s",arr);
   while(arr[i]!='\0')
   { 
	   count ++;
	   i++;
   }
    printf("%d\n",count);
    printf("%lu\n",strlen(arr));
}




