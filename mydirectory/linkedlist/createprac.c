#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createnode()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
struct node createll(int n)
{
    int i;
    struct node* head=createnode();
    struct node * temp=head;
    struct node *newnode;
    for(i=1;i<n;i++)
    {
        newnode=createnode();
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}