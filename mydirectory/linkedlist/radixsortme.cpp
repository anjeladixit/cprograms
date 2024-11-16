#include<iostream>
using namespace std;

int getmax(int a[],int n)
{
   int max=a[0];
   for(int i=1;i<n;i++)
   {
     if(a[i]>max)
     {
        max=a[i];
     }
   }
   return max;
}
int countSort(int a[],int n,int exp)
{
   int output[n];
   int count[10]={ 0 };
   for(int i=0;i<n;i++)
   {
     count[(a[i]/exp)%10]++;
   }
   for(int i=1;i<10;i++)
   {
    count[i]+=count[i-1];
   }
   for(int i=n-1;i>=0;i--)
   {
      output[count[(a[i]/exp)%10]-1]=a[i];
      count[(a[i]/exp)%10]--;
   }
   for(int i=0;i<n;i++)
   {
      a[i]=output[i];
   }
}
void radixsort(int a[],int n)
{
    int max=getmax(a,n);
    for(int exp=1;max/exp>0;exp*=10)
    {
        countSort(a,n,exp);
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
        //printf(" \n");
    }
}
int main()
{
    int n;
    cout<<"enter n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radixsort(a,n);
    print(a,n);
}