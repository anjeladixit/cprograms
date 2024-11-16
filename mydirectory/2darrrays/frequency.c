#include<stdio.h>
int main()
{   
    int n;
    printf("n is");
    scanf("%d",&n);
    printf("enert arrya");
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("enert arrya %d--->",i);
        scanf("%d",&a[i]);

    }
    int num;
    int count=0;
    printf("num");
    scanf("%d",&num);
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            count++;
        }
    }
    printf("%d",count);  

}