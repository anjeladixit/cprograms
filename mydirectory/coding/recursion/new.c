#include <stdio.h>

int main(void)
 {
	// your code goes here
	int a[5]={10,20,30,40,50};
	int b[5]={15,18,25,45,55};
	int c[10];
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
			{
				if(a[j]<=b[k])
				{
					c[i]=a[j];
					

				}
				else{
					c[i]=b[k];
				}
				break;

			}
			break;
		}
		
			
	}
	
	 for(int i=0;i<10;i++)
	 {
		printf(" %d ",c[i]);
	 }     
	    
}
