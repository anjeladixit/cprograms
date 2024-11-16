#include<stdio.h>
void merge(int a[],int b[])
{
    int c[10];
    int j=0;
    int k=0;
    for(int i=0;i<10;i++)
    {
        if(a[j]<=b[k])
        {
            c[i]=a[j];
            j++;
        }
        else{
            c[i]=b[k];
            k++;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf(" %d " , c[i]);

    }

}
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    int b[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&b[i]);

    }
    
    merge(a,b);
    

}