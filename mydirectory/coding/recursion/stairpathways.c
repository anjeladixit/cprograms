#include<stdio.h>
int stair(int n)
{
    if(n==1)
    return 1;
    if(n==2)
    return 2;
    if(n==3)
    return 4; 
    int ways=stair(n-1)+stair(n-2)+stair(n-3);
    return ways;
}

int main()
{
    int n;
    printf("enter stair numbers");
    scanf("%d",&n);
    int ways=stair(n);
    printf("%d",ways);
}