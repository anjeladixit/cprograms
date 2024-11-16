#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
   struct node* prev;
};
struct node* createnode()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node*));
    printf("enter\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
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
        newnode->prev=temp;
        temp=temp->next;

    }
    return head;
}

struct node* deletefirst(struct node* head)
{
    struct node* temp;
    if(head==NULL)
    {
        printf("empty");

    }
    else{
        temp=head;
        head=head->next;
        free(temp);
        printf("deleted");

    }
    return head;
}
struct node* insertatbeg(struct node* head)
{
    struct node*temp=createnode();
    temp->next=head;
    head->prev=temp;
    head=temp;
    printf("inserted\n");
    return head;
}
struct node* insertatlast(struct node* head)
{
    struct node* newnode=createnode();
    struct node* temp=head;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp-> next=newnode;
    newnode->prev=temp;
    return head;
}
struct node* insertatpos(struct node* start,int item,int loc)
{
    struct node* temp=start;
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=NULL;
    ptr->data=item;
    for(int i=0;i<loc;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next->prev=ptr;
    temp->next=ptr;
    return start;
}
struct node* deleteafter(struct node* start,int loc)
{
    struct node* temp= start;
    for(int i=1;i<loc-1;i++)
    {
        temp=temp->next;
    }
    temp->next->next->prev=temp;
    temp->next=temp->next->next;
    return start;
}
void traverse(struct node* start)
{
    struct node* ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node * head=createll(5);
    
    traverse(head);
printf("\n"); 
   head=deleteafter(head,4);
  traverse(head);
   
}