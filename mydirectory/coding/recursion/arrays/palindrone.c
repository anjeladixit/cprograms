#include<stdio.h>
int main()
{
    int a[6];
    for(int i=0;i<=5;i++)
    {  
      printf("the elements ");
      scanf("%d",&a[i]);
    }
    for(int i=0;i<=5;i++)
    {
        printf("%d ",a[i]);
    }
    for(int i=0;i<=5;i++)
    {
        if(a[i]==a[5-i])
        {
            printf("ts is a palindrome");
            break;

        }
        else
           {   printf("no ");
               break;
           }
    }
    
}