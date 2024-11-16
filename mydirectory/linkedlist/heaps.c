#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    // return temp;
}
void minheapify(int arr[],int n,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && arr[left]< arr[smallest])
    {
        smallest=left;
    }
    if (right<n && arr[right]< arr[smallest])
    {
        smallest=right;
    }
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minheapify(arr, n, smallest);
    }
}
void buildheap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        minheapify( arr,  n, i);
    }

}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
int  pop(int arr[],int n)
{
    int smallestno=arr[0];
    arr[0]=arr[n-1];
    n--;
    minheapify(arr,n,0);
    return smallestno;

}
int main()
{
    int arr[4]={4,3,2,1};
    buildheap(arr,4);
    print(arr,4);
        printf("\n");
    printf("%d",pop(arr,4));
    printf("\n");
     print(arr,3);
}