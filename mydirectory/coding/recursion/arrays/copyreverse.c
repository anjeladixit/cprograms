#include<stdio.h>
int main()
{
    int a[5]={11,23,34,45,56};
    int b[5];
    for(int i=0;i<=4;i++)
    {
        b[i]=a[4-i];
    }
    for(int i=0;i<=4;i++)
    {
        printf("%d ",b[i]);
    }
    
}