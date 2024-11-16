#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    char a [7];
	    int count=0;
		

	    scanf("%c %c %c %c %c %c",&a,&b,&c,&d,&e,&f);
	     char arr[6]={a,b,c,d,e,f};
	    for(int i=0;i<4;i++)
	    {
	        if(arr[i]=='W' && arr[i+1]=='W' && arr[i+2]=='W')
	            count++;
	       
	    }
	    if(count==0)
	        printf("no\n");
	    else 
	      printf("yes\n");
	    
	}

}
