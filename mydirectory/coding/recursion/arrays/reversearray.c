#include<stdio.h>
int main()
{
    int a[5]={21,23,34,45,56};
    int b;
    for(int i=0;i<=4;i++)
    {  
       if(i<4-i) 
       {  b=a[i]; 
          a[i]=a[4-i];
          a[4-i]=b;
       }
      
      printf("%d ",a[i]);
    }
    
}