#include<stdio.h>
#include<string.h>

char a[5];
int top=-1;
void push(char x)
{
  
        top++;
        a[top]=x;
      
}
void  pop()
{
        top--;
}
int main()
{
int top=-1;
 int n;
 scanf("%d",&n);
 char a[n];
 int i;
 printf("Enter the string : \n" );
 for(int i=0;i<n;i++)
 {
    scanf("%s",&a[i]);
 }
 for(i=0;i<strlen(a);i++)
  {
   push(a[i]);
   for(int j=i+1;j<n;j++)
    {
    if(a[j]==')')
    pop();
    }
  }
  if(top==-1)
     printf("balanced");
  else 
    printf("no");

}