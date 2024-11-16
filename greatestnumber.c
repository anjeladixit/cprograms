#include <stdio.h>
int main()
{
    int num1,num2,num3,num4;
    printf("enter a number",num1);
    scanf("%d",&num1);
     printf("enter a number",num2);
    scanf("%d",&num2);
     printf("enter a number",num3);
    scanf("%d",&num3);
     printf("enter a number",num4);
    scanf("%d",&num4);
    if((num1>num2)&&(num1>num3)&&(num1>num4))
    { 
        printf("greatest number is %d",num1);
    }  
    if((num2>num1)&&(num2>num3)&&(num2>num4))
    { 
        printf("greatest number is %d",num2);
    }  
    if((num3>num2)&&(num3>num1)&&(num3>num4))
    { 
        printf("greatest number is %d",num3);
    }  
    if((num4>num2)&&(num4>num3)&&(num4>num1))
    { 
        printf("greatest number is %d",num4);
    }  
}