#include<stdio.h>
int main() {
    int t;
    scanf("%d", &t);

   for(int i=0;i<t;i++)
   {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int c = 0;
        for (int i = 0; i < n;) {
            if (a[i] == i + 1)
            {
             int temp=a[i-1];
             a[i-1]=a[i];
             a[i]=temp;
                c++;
            } 
            else {
                i++;
            }
        }

        printf("%d\n", c);
    }

} 
