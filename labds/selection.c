#include<stdio.h>
void  select(int a[],int n)
{
    
    for(int i=0;i<n-1;i++)
    {
        int m=i;
    for(int j=i+1;j<n;j++)
     {  
       if(a[j]<=a[m])
       {
        m=j;
       }
     }
     int t=a[m];
       a[m]=a[i];
       a[i]=t;
    }
    
    
}

int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    select(a,n);
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);

    }
    
}
