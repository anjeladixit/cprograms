#include <stdio.h>
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=n;j>i;j--)
        {
            printf("*");
        }
        printf("\n");

    }

}