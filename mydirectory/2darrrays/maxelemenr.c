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
    int max=a[0][0];
    int min=a[0][0];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(max<a[i][j])
            {
                max=a[i][j];
                row=i;
                col=j;
            }
        }   
        for(int j=0;j<c;j++)
        {
            if(min>a[i][j])
            {
                min=a[i][j];
                row1=i;
                col1=j;
            }
        }
    }
    printf("max is %d\n",max);
    printf("%d %d\n ",row,col);
    printf("min is %d\n",min);
    printf("%d %d\n ",row1,col1);
}