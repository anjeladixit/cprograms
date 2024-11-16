#include<stdio.h>
void selection(int a[],int n)
{
    int s;
    for(int i=0;i<n-1;i++)
    {
        s=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[s])
            {
                s=j;
            }

        }
        int t=a[s];
        a[s]=a[i];
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
    selection(a,n);
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);

    }


}