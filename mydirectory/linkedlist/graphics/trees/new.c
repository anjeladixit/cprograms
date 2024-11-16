#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
struct node* createll(int x)
{
    struct node* head=createnode();
    struct node* temp=head;
    struct node* newnode;
    for(int i=1;i<x;i++)
    {
       newnode=createnode();
       temp->next=newnode;
       temp=temp->next;
    }
    return head;

}
void transverse(struct node *start)
    {
        struct node *ptr=start;
        printf("the elements are");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;

        }
    }
int main()
{
     struct node*head =createll(4);

    transverse(head);
}