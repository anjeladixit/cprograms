#include<stdio.h>
int binary(int a[],int n,int k)
{
    int s=0;
    int e=n-1;
    int m=(e+s)/2;
    while(s<=e)
    {
        if(a[m]==k)
        {
            return m;
        }
        if(k<a[m])
        {
            e=m-1;
        }
        else
        {
            s=m+1;
        }
        m=(e+s)/2;

    }
    return -1;
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
    int k;
    scanf("%d",&k);
    int ind=binary(a,n,k);
    printf("%d",ind);
}