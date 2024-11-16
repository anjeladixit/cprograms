#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;

}

char pop()
{
    if(top == -1)
      return 1;
    else
      return stack[top--];
}

int priority(char c)
{   if(c==')')
    return 0;
    else if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
}
void strrev(stack)
{
for(int i=0;i<strlen(stack);i++)
  {
   push(stack[i]);
  }
 for(int i=0;i<strlen(stack);i++)
  {
      stack[i]=pop(); 
  }

}

void infixtoprefix(char infix[100],char prefix[100])
{
    char temp,x;
    int i=0,j=0;
    strrev(infix);
    for (int i = 0; i < ; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    while(infix[i]!='\0')
    {
        temp=infix[i];
       if(isalnum(temp))
        {
            prefix[j++]=temp;
        }
        else if(temp==')')
         push(temp);
        else if(temp=='(')
            {
         while((x=pop())!=')')
         {
          prefix[j++]=x;
           }
          }
        else
        {  while(priority(a[top])>=priority(temp))
            {prefix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)
    prefix[j++]=pop();
    prefix[j]='\0';
    strrev(prefix);
}
int main()
{
    char infix[100],prefix[100];
    printf("Enter the infix expression\n");
     scanf("%s",infix);
    printf("The infix expression is %s\n",infix);
    infixtoprefix(infix, prefix);
    printf("The prefix expression is %s\n",prefix);
}