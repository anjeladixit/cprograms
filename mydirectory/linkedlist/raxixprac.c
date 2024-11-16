#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof (struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
int findmax(struct node* head)
{
    int max=head->data;
    while(head!=NULL)
    {
        if(head->data>max)
        {
            max=head->data;
        }
        head=head->next;
    }
    return max;
}
int getdigit(int number,int digitplace)
{
    return(number/digitplace)%10;
}
struct node* insert(struct node* head,struct node* newnode)
{
    if( head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node* temp=head;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
struct node* countingsort(struct node* head,int digitplace)
{
    struct node* buckets[10]={NULL};
    struct node* current=head;
    while(current !=NULL)
    {
        int digit=getdigit(current->data,digitplace);
        struct node* newnode=current->next;
        current->next=NULL;
       buckets[digit]=insert(buckets[digit],current);
        current=newnode;
    }
    struct node* newhead=NULL;
    struct node* tail=NULL;
    for(int i=0;i<10;i++)
    {
     if(buckets[i]!=NULL)
     {
      if(newhead==NULL)
        {
            newhead=buckets[i];

        }
        else
        {
            tail->next=buckets[i];
        }
       tail=buckets[i];
       while(tail->next!=NULL)
       {
        tail=tail->next;
       } 
     }      
    }
    return newhead;
}
struct node* radix(struct node* head)
{
    int max=findmax(head);
    int digitplace=1;
    while(max/digitplace>0)
    {
        head=countingsort(head,digitplace);
        digitplace *=10;

    }
    return head;
}
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = create(136);
    head=insert(head, create(487));
    head=insert(head, create(358));
    head=insert(head, create(469));
    head=insert(head, create(570));
    head=insert(head, create(247));
    head=insert(head, create(205));
    head=insert(head, create(609));

    printf("Original List:\n");
    printList(head);

   head =radix( head); 

    printf("\nSorted List:\n");
    printList(head);

    return 0;
}
