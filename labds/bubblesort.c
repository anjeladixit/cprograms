#include<stdio.h>
void bubble(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<(n-1-i);j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;

            }
        }
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
    bubble(a,n);
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);

    }


}