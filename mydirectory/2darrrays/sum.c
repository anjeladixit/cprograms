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
    int max=0;
    int in;
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
    {   int sum=0;
        for(int j=0;j<c;j++)
        {
            sum=sum+a[i][j];
            
        
        }   
        if(sum>max)
        {
            max=sum;
            in=i;
        }
        
    }
    printf("%d  %d",max,in);
}    