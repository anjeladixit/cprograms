#include<stdio.h>
int main()
{
    int r;
    int row;
    int col;
    int row1;
    int col1;
    printf("enter rows");
    scanf("%d",&r);
    int c;
    printf("enter cols");
    scanf("%d",&c);
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
}