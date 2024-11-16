#include <stdio.h>
int main()
{
    int num;
    int power;
    int b ;
    printf("enter a number",num);
    scanf("%d",&num);
    printf("enter powerc",power);
    scanf("%d",&power);
    for (b=1;b<=power;++b)
    {
      num=num* num ;
      
      
    }
    printf("ans is %d",num);
}   