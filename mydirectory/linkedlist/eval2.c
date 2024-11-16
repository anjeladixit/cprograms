#include<stdio.h>
#include<stdlib.h>
struct node{
 int expo;
 int coeff;
 struct node* next;
};
struct node* create(struct node* head,int expo,int coeff)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->coeff=coeff;
    temp->expo=expo;
   temp->next=NULL;
   struct node* current;
  if(head==NULL || expo>head->expo)
    {
        temp->next=head;
        head=temp;
    }
    else 
    {
       current=head;
        while(current->next  !=NULL && current->next->expo>expo)
                current=current->next;
        temp->next=current->next;
         current->next=temp;
    }
    return head;

}
struct node* insert(struct node* head){
//     int t;
//    printf("no of test");
//    scanf("%d",&t);
//    for(int i=0;i<t;i++)
//    {
   int n;
   int coeff;
   int expo;
   printf("no of terms");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
        {
            printf("coefficient of %d",i+1);
            scanf("%d",&coeff);
            head=create(head,i,coeff);
        }
  
       
//    }
   return head;
}
void degree(struct node* head)
{
    struct node* temp=head;
    while(temp->coeff==0)

    {
        temp=temp->next;
    }
    printf("%d",temp->expo);
}

int main()

{ 
    int t;
    printf("no of test");
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
    struct node* head=NULL;
     head=insert(head);
   degree(head);
}
}