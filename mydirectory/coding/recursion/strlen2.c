#include <stdio.h>
//#include<string.h>
//int strlen(int a[])
int strlen(char arr[])
{   int count=0;
    int i=0;
    while(arr[i]!='\0')
   { 
	   count ++;
	   i++;
   }
   return count;
}
int main()
{
   char arr[100];
   gets(arr);
   printf("%d",strlen(arr));

}

