#include<stdio.h>
int main()
{
    
    int arr[5]={12,32,43,55,71};
    int max=arr[0];
    int max2=arr[0];
    int c;
    for(int i=0;i<=4;i++)
    {
       if(max<arr[i])
       {
          max=arr[i];
          c=i;
       }
    
    }
    printf("%d\n",c);
    for(int i=0;i<=4;i++)
    {
        if(max2<arr[i] && i!=c)
        { 
           max2=arr[i];
        }
    }
    printf("%d",max2);
} 