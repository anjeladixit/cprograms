#include<stdio.h>
int power(int a ,int b)
{
    if(b==0)
    return 1;
    int pow=a*power(a,b-1);
    return pow;

}
int main()
{
    int a;
    printf("enter a number");
    scanf("%d",&a);
    int b;
    printf("enter a power raised number");
    scanf("%d",&b);
    int p=power(a,b);
    printf("%d",p);
}