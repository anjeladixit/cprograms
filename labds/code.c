#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n;
	    scanf("%d",&n);
	    int s[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&s[i]);
	    }
	    int m=0;
	    int c=0;
		int count =0;
	    for(int i=0;i<n;i++)
	    {
	        while(s[i] !=1)
			
	        {
	            c++;
	            if(c>m)
	                m=c;
	        }
			while(s[i]==1)
			{
				count++;
			}
	    }
	    printf("%d\n",m+count);
	}

}
