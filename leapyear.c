#include <stdio.h>
int main()
{
    int year;
    printf("enter a year",year);
    scanf("%d",&year);
    if(year%2==0 && year%4==0 && year%400==0)
    {
        printf("it is leap year");

    }
    else{
        printf("not leap year");
    }
}