#include<stdio.h>
int fibo(int n)
{
    if(n==1 || n==2)
    return 1;
    int f=fibo(n-1)+fibo(n-2);
    return f;

}
int main()
{
    int n;
    scanf("%d",&n);
    int x= fibo(n) ;
    printf("%d",x);

    
}