#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int n;
	    scanf("%d",&n);
	    char s[n];
	    scanf("%s",s);
	    int c=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
	           
               { c++;
                break;
               }
               
	   }
	   if(c==1)
	     printf("yes\n");
	   else
	     printf("no");
	}

}

