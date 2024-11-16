
#include <stdio.h>
int max(int a,int b)
{
    if(a>b)
      return a;
    else
      return b;
}
int min(int a,int b)
{
    if(a>b)
      return b;
    else
      return a;
}
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    int a,b;
	    int c=0;
	    
	    scanf("%d %d",&a,&b);
	    if(a%3==0 || b%3==0)
	       printf("0");
	    else if(a%3!=0 || b%3!=0)
	    {  
	        while(a%3==0 || b%3==0)

	        {
	            a=max(a,b)-min(a,b);
	            c++;
	            b=max(a,b)-min(a,b);
	            c++;
	        }
	        printf("%d",c);
	    }
	}

}



