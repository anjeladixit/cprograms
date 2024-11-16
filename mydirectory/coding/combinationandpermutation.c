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
    printf("enter a number");
    scanf("%d",&n);
    int r;
    printf("enter a r");
    scanf("%d",&r);
    int fact=factorial(n)/(factorial(n-r)*factorial(r));
    printf("%d",fact);
}