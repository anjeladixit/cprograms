#include<stdio.h>
void insertion(int a[],int n)
{
   for(int i=1;i<n;i++)
   {
     int j=i-1;
     int k=a[i];
     while(j>=0 && k<=a[j])
     {
        a[j+1]=a[j];
        j--;
     }
     a[j+1]=k;
   }
}

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
    insertion(a,n);

    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);

    }

    selection(a,n);

    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);

    }

    bubble(a,n);

    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);

    }




}
