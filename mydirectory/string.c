#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
    scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n;
	    int max;
	    scanf("%d",&n);
	    char s[n];
	    scanf("%s",s);
	    for(int i=0;i<n;i++)
	    {
	         max=s[0];
	        if(s[i+1]>max)
	        {
	            max=s[i+1];
	        }
           
	    }
        printf("%d",max);
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]!=max)
	          printf("%c",s[i]);
	    }
	}

}

