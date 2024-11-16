#include<stdio.h>
int main()
{
    int a[6]={1,7,3,7,4,5};
    for(int i=0;i<=5;i++)
    {
        for(int j=i+1;j<=5;j++)
        {
            if(a[i]==a[j])
               printf("is duplicate %d",a[j]);
            
        }
    }
}