#include<stdio.h>
#include<string.h>
char stack[4];
int top=-1;
void push(char x)
{
    if(top==3)
      printf("over");
    else
    {
        top++;
        stack[top]=x;
    }
      
}
char pop()
{
    char item;
    if(top==-1)
    {
        printf("empty");

    }
    else
    {
        item=stack[top];
        top--;
        printf("%c",item);
    }
}
int main()
{


 char stack[4];
 int i;
 printf("Enter the string : \n" );
 gets(stack);
 for(i=0;i<strlen(stack);i++)
  {
   push(stack[i]);
  }
 for(i=0;i<strlen(stack);i++)
  {
      stack[i]=pop(); 
  }
}