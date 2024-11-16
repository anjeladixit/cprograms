#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node*next;
};
struct node* newnode(int data,int priority)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->priority=priority;
    temp->next=NULL;
    return temp;
}
int isempty(struct node* head)
{
    return (head==NULL);

}
struct node* insert(struct node* head,int data,int priority)
{
    struct node* start=head;
    struct node* temp=newnode(data,priority);
    if(head==NULL|| head->priority<priority)
    {
        temp->next=head;
        head=temp;
    }
    else{
       while(start->next!=NULL && start->next->priority>=priority)
       {
          start=start->next;
       }
       temp->next=start->next;
       start->next=temp;

    }
    return head;
}
void display(struct node* head) {
    if (isempty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}
int main() {
    struct node* pq = NULL;

    pq = insert(pq, 10, 2);
    pq = insert(pq, 20, 1);
    pq = insert(pq, 15, 3);
    pq = insert(pq, 35, 4);
    printf("Queue after insertions:\n");
    display(pq);

    // pq = delete(pq);
    // printf("\nDeleted element\n");

    // printf("\nQueue after deletion:\n");
    // display(pq);

    return 0;
}