#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	for(int i=0;i<t;i++)
	{
	    int a,b,c,d;
	    scanf("%d %d %d %d",&a,&b,&c,&d);
	    if(a<b)
	       a=a+c;
	    else
	      b=b+c;
	    if(b<=a)
	      b=b+d;
	    else 
	      a=a+d;
	    if(a<=b)
	       printf("%d\n",b);
	    else
	       printf("n\n");
	}
}