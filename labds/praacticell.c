#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* createnode()
{
    struct node* temp;
    temp=(struct node *)malloc(sizeof(struct node));
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

//     for(int i=0;i<loc;i++)
//     {
//         temp=temp->next;
//     }
//     temp->prev->next=temp->next;
//     temp->next->prev=temp->prev;
//     free(temp);
//     printf("de");
//     return start;
//     }
//     // return  start;
// // }
struct node* reverse(struct node* head)
{
   struct node* temp=NULL;
   struct node* current=head;
   while(current!=NULL)
   {
      temp=current->prev;
      current->prev=current->next;
      current->next=temp;
      current=current->prev;
   }
   if(temp !=NULL)
       head=temp->prev;
return head;    

}
void traverse(struct node* head)
{
    struct node* temp=head;
    
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
        
    }
    

}
int main()
{
  
    struct node* head=createll(5);
      traverse(head);
    head=deleteafter(head,1);
    traverse(head);
    
}