#include<stdio.h>
int main()
{
    int a[6]={6,2,2,3,2,6};
    for(int i=0;i<6;i++)
    {
        for(int k=i+1;k<6 ;k++)
        {
            if(a[i]==a[k])
               printf("%d\n",a[i]);
            else 
            continue;
        }
        i++;
    }

}