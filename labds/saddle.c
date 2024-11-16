#include<stdio.h>
int main()
{
    int m;
    int n;
    int ind=0;
    int c=0;
    scanf("%d %d",&m,&n);
    int a[m][n];
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        int min=a[i][0];
        for(int j=0;j<n;j++)
        {
           
           if(a[i][j]<=min)
           {
            min=a[i][j];
            ind=j;
           }
        }
           for(int k=0;k<m;k++)
           
           {
             if(a[k][ind]>min)
             {
                break;

             }
             else 
             {
                printf("%d",min);
             }
             
             
             }   
    }

}