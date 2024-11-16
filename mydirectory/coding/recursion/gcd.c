#include <stdio.h>
int gcd(int a , int b)
{

}

int main()
{
    int num1;
    printf("enter number 1-->");
    scanf("%d",&num1);
    int num2;
    printf("enter number 2-->");
    scanf("%d",&num2);
    int b=gcd(num1,num2);
    printf("hcf is %d",b);
}