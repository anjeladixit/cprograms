#include <stdio.h>
int main()
{
    int n;
    int i;
    int pow;
    scanf("%d",&n);
    scanf("%d",&pow);
    for(i=1;i<=pow;i++)
    {
      n=n*n;
      
    }
    printf("%d",n);
}