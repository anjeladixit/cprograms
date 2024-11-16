#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n;
	    scanf("%d",&n);
	    char p[n];
	    scanf("%s",p);
	    char c[n];
	    scanf("%s",c);
	    int k,i,j=0;
	    for(int i,j=0;i<n;i++)
	    {while(p[i]!=c[j])
	        {  
                
                    
                j=j+2;
	            k++;
                if(c[j]>90)
	               c[j]=65;
                
                
	        }}
	        printf("%d ",k);
	   
	    
	}

}

