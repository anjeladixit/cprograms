#include<stdio.h>
void reverse(int a[])
{
    for(int i=0;i<=4;i++)
    {  
       if(i<4-i) 
       { int b=a[i]; 
          a[i]=a[4-i];
          a[4-i]=b;
       }
       
      
    }
    return ;
}
int main()
{
    int a[5]={1,2,3,4,5};
    reverse(a);
    for(int i=0;i<=4;i++)
    {
        printf("%d",a[i]);
    }

}