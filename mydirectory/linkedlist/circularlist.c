#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node *next;
};

void cn(struct node *c, int dd) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->d = dd;
    c->next = n;
    c = n;
    c->next = NULL;
}

int main() {
    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *c = a;
    c->d = 1;
    
    
    c->next=(struct node *)malloc(sizeof(struct node));
    c=c->next;
    c->d=2;
    
    c->next=(struct node *)malloc(sizeof(struct node));
    c=c->next;
    c->d=2;
    
    c->next=(struct node *)malloc(sizeof(struct node));
    c=c->next;
    c->d=3;
    
     c->next=(struct node *)malloc(sizeof(struct node));
    c=c->next;
    c->d=3;
    
    c->next=a;
    
    int t=10;
    c=a;
    
    
    int del=2;
    do{
        
        printf("%d\n",c->d);
        c=c->next;
    }
    while(c!=a);
    
  
    return 0;
}