#include <stdio.h>
int main()
{
    int n;
    int s;
    int r=0;
    int t=0;
    int u;
    scanf("%d",&n);
    while (n!=0)
    {
        s=n%10;
        r=r+s;
        n=n/10;
    }
    while  (r%10 !=0)
    {
        u=r%10;
        t=t+u;
        r=r/10;
    }
    printf("answer is %d",t);
}