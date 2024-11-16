#include<stdio.h>

int main(void) {
	// your code goes 
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,l,r;
	    int min=0;
	    int max=0;
	    int h=0;
		int k=0;
	    scanf("%d %d %d",&n,&l,&r);
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&a[i]);
	        if(a[i]>=l && a[i]<=r)
	            h++;
	            if(h>max)
	            max=h;
	        else
	          h--;
	          if(h<min)
	          min=h;
	    }
	   printf("%d %d\n",max,min);
	}

}
