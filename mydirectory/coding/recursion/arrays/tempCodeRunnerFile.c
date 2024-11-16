#include<stdio.h>
int main()
{
    
    int arr[5]={12,32,43,5,21};
    int max=arr[0];
    for(int i=0;i<=4;i++)
    {
       if(max<arr[i])
       {
          max=arr[i];
       }
    printf("%d",max);
    }
} 