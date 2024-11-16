#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n;
	    
	    int bin[32];
	    int i=0;
	    int c=0;
	    while(n>0)
	    {
	        bin[i]=n%2;
	        n=n/2;
	        i++;
	    }
	    for(int k=i-1;k>=0;k--)
	    {
	        
	        c=bin[k];
	    }
	    if(c%2==0)
	      printf("%d even\n",c);
	     else
	      printf("odd\n");
	}

}