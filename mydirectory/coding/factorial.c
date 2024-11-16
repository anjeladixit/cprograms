#include<stdio.h>
int factorial(int n)
{
    int f;
    if(n==1 || n==0) return 1;
    return n*factorial(n-1);
}
int main()
{
    int n;
    printf("enter n");
    scanf("%d",&n);
    int f=factorial(n);
    printf("%d",f);
}