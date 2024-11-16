#include<stdio.h>
int main()
{
    int a[5]={1,1,4,3,3};
    int c=0;
    for(int i=0;i<=4;i++)
    {   
        for(int j=i+1;j<=4;j++)
        {
            if(a[i]==a[j])
            { 
                c=1;
            }
        }
        
    }
    if(c==0)
            printf("h");
}