#include <stdio.h>
int main()
{
   char arr[100];
   gets(arr);
   int word=1;
   int i=0;
   while(arr[i]!='\0')
   {  
    if(arr[i]==(char)32 || (arr[i]==(char)32 && arr[i+1]==(char)32))
    {
        word++;
    }
    i++;
   }
   printf("%d",word);
}

