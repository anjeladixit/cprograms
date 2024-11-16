#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    } 
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    } 
    printf("\n");
    int temp;
    for(int k=0;k<n-1;k++)
    {
        for (int i=0;i<n-1;i++)
    {
        if(arr[i]<arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;

        }
     
       
    }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}