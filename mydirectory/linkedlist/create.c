#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode()
{   
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
struct node *createll(int n)
{
    int i;
    struct node *head=createnode();
    struct node *temp=head;
    struct node *newnode;
    for(i=1;i<n;i++)
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
struct node *addbeg(struct node *head)
{
    
    struct node * newnode=createnode();
    newnode->next=head;
    head=newnode;
    return head;
}
struct node *addatpos(struct node *head,int pos)
{
    
    struct node * newnode=createnode();
    struct node *temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node *deletefrombeg(struct node *start)
{
    struct node *ptr=start;
    start=start->next;
    free(ptr);
    printf("deleted");
    return start;
}


int main()
{
    struct node*head =createll(4);
    head=addbeg(head);
    transverse(head);
   head= deletefrombeg(head);
   transverse(head);
   head= addatpos(head,3);
   transverse(head);


}
