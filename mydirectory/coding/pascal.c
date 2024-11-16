#include<stdio.h>
int factorial(int x)
{
    int f=1;
    for(int i=1;i<=x;i++)
    {
        f=f*i;
        
    }
    return f;
    
}
int main()
{
    int n;
    printf("enter a number of rows ");
    scanf("%d",&n);
    for (int i=0;i<=n;i++)
    {
        for (int k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<=i;j++)
        {
            int fact=factorial(i)/(factorial(i-j)*factorial(j));
            printf("%d",fact);
            printf(" ");
            
        }
        printf("\n");
        
    }
    
       
}