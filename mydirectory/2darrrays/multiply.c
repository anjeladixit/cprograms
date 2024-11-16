#include<stdio.h>
int main()
{
    int r1;
    int r2;
    int c1;
    int c2;
    printf("enter rows");
    scanf("%d",&r1);
    printf("enter cols");
    scanf("%d",&c1);
    int a[r1][c1];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter rows");
    scanf("%d",&r2);
    printf("enter cols");
    scanf("%d",&c2);
    int b[r2][c2];
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int c[r1][c2];
    int rc=r2;
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
          {
            c[r1][c2]=0;
            for(int k=0;k<rc;k++)
           {
               c[i][j]+=a[i][k]*b[k][j];
           }

        }
    }

    for (int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            printf("%d",c[i][j]);
        }
        printf("\n");
    }
}    