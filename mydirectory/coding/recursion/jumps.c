#include<stdio.h>
int main()
{
   int n;
   printf("n");
   scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   
    int count=0;
    int j=0;
    while(j<=n)
    {
      j=a[j]+j;
      count++;
    }
    printf("%d",count);
 
}
   