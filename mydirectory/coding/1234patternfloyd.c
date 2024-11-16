#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+2;j++)
        {
           if(j==n+2 || i==n || j==1 || i==1)
           {
            printf("*");
           }
           else
           {
            printf(" ");
            
           }
        }
        printf("\n");
    }
}
