#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(struct node* head,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
   temp->next=NULL;
   struct node* current;
   if(head==NULL)
   {
     temp->next=head;
     head=temp;
   }
   else
   {
    current=head;
    while(current->next!=NULL)
    {
        current=current->next;

    }
    temp->next=current->next;
    current->next=temp;

   }
   return head;
}
struct node* insert(struct node* head)
{
    int n;
  int data;
   printf("no of terms");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
        {
            printf("data of %d",i+1);
            scanf("%d",&data);
            head=create(head,data);
        }
  
        return head;
//    }
}
  
struct node* revert(struct node* head,int n,int k)
{
    for(int i=0;i<n;i+k)
    {
    struct node* temp=head;
    struct node* prev=NULL;
    struct node* next=NULL;
    prev=temp->next;
    next=temp;
    temp=prev;
    }
return head;
}
void print(struct node* head)
{
    struct node* temp=head;
    while(temp->next!=NULL)
    {
       printf("%d",temp->data);
       temp=temp->next;
    }
}

int main()
{
    int n;
    printf("n");
    scanf("%d",&n);
    int k;
    printf("k");
    scanf("%d",&k);
    struct node* head=NULL;
    head=insert(head);
    head=revert(head,n,k);
    print(head);
}
