#include <stdio.h>
int min(int a , int b)
{
    int minimum;
    if(a>b)
    minimum=b;
    else
    minimum =a;
    return minimum;
}
int main()
{
    int num1;
    printf("enter number 1-->");
    scanf("%d",&num1);
    int num2;
    printf("enter number 2-->");
    scanf("%d",&num2);
    int b=0;
    for(int i=1;i<=min(num1,num2);i++)
    {
       if(num1%i==0 && num2%i==0)
         b=i;
    }  
    printf("hcf is %d",b);
}