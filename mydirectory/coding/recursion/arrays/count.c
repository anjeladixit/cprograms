#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int count=0;
    int arr[7]={1,2,19,14,5,6,7};
    for(int i=0;i<=6;i++)
    {
       if(arr[i]>x)
          count+=1;
    }
    printf("%d",count);
}