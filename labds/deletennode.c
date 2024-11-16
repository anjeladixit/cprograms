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
    for (int i=1;i<n;i++)
    {
        newnode=createnode();
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
    
}
void traverse(struct node* start)
{
    int c=0;
    struct node* ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
       
    }
    
}
int count(struct node* start)
{
    int c=0;
    struct node* ptr=start;
    while(ptr!=NULL)
    {
       
        ptr=ptr->next;
       c++;
    }
    return c;
}
struct node* nnode(struct node* head,int n)
{
    struct node* temp;
    struct node* p1;
    temp=head;
   for(int i=1;i<n;i++)
   {
    p1=temp;
    temp=temp->next;

   }
   p1->next=temp->next;
   free(temp);
   return head;
}
int main()
{
    
    struct node* head=createll(5);
  int c= count(head);
   head=nnode(head,c-2+1);
   traverse(head);

}