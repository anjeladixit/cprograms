#include <stdio.h>
int main()
{ int b;
  printf("enter a marks ",b);
  scanf("%d",&b);

  switch (b/10)
  {
  case 9:
    printf("A");
    break;

  case 8:
    printf("B");
    break;

  case 7:
    printf("C");
    break;

  default :
    printf("D");
    break;
  }
} 