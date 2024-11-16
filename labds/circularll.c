#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
struct node* createll(int n)
{
    struct node* head=createnode();
    struct node* temp=head;
    struct node* newnode;
    for(int i=1;i<n;i++)
    {
        newnode=createnode();
        temp->next=newnode;
        temp=temp->next;
    }
    temp->next=head;
    return head;
}
void traverse(struct node* head)
{
    struct node* ptr=head;
    while(ptr->next != head)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
int main()
{
    struct node* head=createll(5);
    traverse(head);
}