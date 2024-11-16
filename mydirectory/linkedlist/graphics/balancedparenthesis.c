#include<stdio.h>
#include<stdio.h>
#include<string.h>

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
int ismatching(char char1, char char2) {
    if (char1 == '(' && char2 == ')') {
        return 1;
    } else if (char1 == '[' && char2 == ']') {
        return 1;
    } else if (char1 == '{' && char2 == '}') {
        return 1;
    } else {
        return 0;
    }
}
int isBalanced(char* a) {
    int i;
    for (i = 0; i < strlen(a); i++) {
        if (a[i] == '(' ||a[i] == '[' || a[i] == '{') {
            push(a[i]);
        } else if (a[i] == ')' ||a[i] == ']' || a[i] == '}')
         {
            if (top == -1) {
                return 0; 
            } else if (!ismatching(pop(), a[i])) {
                return 0; 
            }
        }
    }
     if (top == -1) {
        return 1; 
    } else {
        return 0; 
    }
}
int main() {
   char a[100];
   printf("Input an expression  ");
   scanf("%s", a);
   if (isBalanced(a)) {
       printf("The expression is balanced.\n");
   } else {
       printf("The expression is not balanced.\n");
   }
   return 0;
}
