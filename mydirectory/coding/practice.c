#include <stdio.h>
int main()
{
   int n;
   int idx=0;
   int temp[7]; 
   int a[]={2,3,3,3,4,4,4};
   for(int i=0;i<6;i++)
   {
     if(a[i]!=a[i+1])
     {
        temp[idx]=a[i];
        idx++;
     }
    
   }
    temp[idx++]=a[6];

    for(int i=0;i<=idx;i++)
    {
        a[i]=temp[i];
    }
    for(int i=0;i<idx;i++)
    {
        printf("%d",a[i]);
    }


}