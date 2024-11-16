#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
          for(int j=1;j<=n-i;j++)
          {
            printf(" ");
          }
          for(int k=1;k<=i;k++)
          { int a=k+64;
            int  t;
            t=(char)a;
            printf("%c",t);

          }
        printf("\n");
    }
}
