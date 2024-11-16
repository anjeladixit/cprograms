// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     int priority;
//     struct node* next;
// };
// struct node* newnode(int data,int priority)
// {
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     temp->data=data;
//     temp->priority=priority;
//     temp->next=NULL;
//     return temp;
// }
// int isempty(struct node* head)
// {
//     return (head==NULL);
// }
// struct node* insert(struct node* head,int data,int priority)
// {
//     struct node* start=head;
//     struct node* temp=newnode(data,priority);
//     if(head==NULL || head->priority>priority)
//     {
//         temp->next=head;
//         head=temp;
//     }
//     else{
//         while(start->next !=NULL && start->next->priority<priority)
//         {
//             start=start->next;
//         }
//         temp->next=start->next;
//         start->next=temp;
//     }
// return head;
// }
// void display(struct node* head)
// {
//     struct node* temp=head;
//     while(temp !=NULL)
//     {
//         printf(" priority %d   data %d \n",temp->priority,temp->data);
//         temp=temp->next;
//     }
// }
// int main()
// {
//     struct node* pq=NULL;
//     pq=insert(pq,7,12);
//     pq=insert(pq,2,2);
//     pq=insert(pq,9,15);
//     pq=insert(pq,3,8);
//     pq=insert(pq,10,18);
//     display(pq);
// }


// using only data as priority
// #include<stdio.h>         
// #include<stdlib.h>
// struct node{
//     int data;
//     // int priority;
//     struct node* next;
// };
// struct node* newnode(int data)
// {
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     temp->data=data;
//     // temp->priority=priority;
//     temp->next=NULL;
//     return temp;
// }
// int isempty(struct node* head)
// {
//     return (head==NULL);
// }
// struct node* insert(struct node* head,int data)
// {
//     struct node* start=head;
//     struct node* temp=newnode(data);
//     if(head==NULL || head->data>data)
//     {
//         temp->next=head;
//         head=temp;
//     }
//     else{
//         while(start->next !=NULL && start->next->data<data)
//         {
//             start=start->next;
//         }
//         temp->next=start->next;
//         start->next=temp;
//     }
// return head;
// }
// void display(struct node* head)
// {
//     struct node* temp=head;
//     while(temp !=NULL)
//     {
//         printf("  data %d \n",temp->data);
//         temp=temp->next;
//     }
// }
// int main()
// {
//     struct node* pq=NULL;
//     pq=insert(pq,7);
//     pq=insert(pq,2);
//     pq=insert(pq,9);
//     pq=insert(pq,3);
//     pq=insert(pq,10);
//     display(pq);
// }


// using doubly ll
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node* prev;
//     struct node* next;
// };
// struct node* newnode(int data)
// {
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     temp->data=data;
//     temp->next=NULL;
//     temp->prev=NULL;
//     return temp;
// }
// int isempty(struct node* head)
// {
//     return (head==NULL);
// }
// struct node* insert(struct node* head,int data)
// {
//     struct node* start=head;
//     struct node* temp=newnode(data);
//     if(head==NULL || head->data>data)
//     {
//          temp->next = head;
//         if (head != NULL)
//             head->prev = temp;
//         head = temp;
//     }
//     else{
//         while(start->next !=NULL && start->next->data<data)
//         {
//             start=start->next;

//             //  if (start->next != NULL)

//             //    start->next->prev=start;
//         }
//         temp->next=start->next;
//           if (start->next != NULL)
//             start->next->prev = temp;
//         start->next=temp;
//         temp->prev=start;
//     }
// return head;
// }
// void display(struct node* head)
// {
//     struct node* temp=head;
//     while(temp !=NULL)
//     {
//         printf("  data %d \n",temp->data);
//         temp=temp->next;
//     }
// }
// int main()
// {
//     struct node* pq=NULL;
//     pq=insert(pq,12);
//     pq=insert(pq,13);
//     pq=insert(pq,10);
//     pq=insert(pq,8);
//     pq=insert(pq,1);
//     display(pq);
// }


//using circular ll
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
   // struct node* prev;
    struct node* next;
};
struct node* newnode(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    //temp->prev=NULL;
    return temp;
}
int isempty(struct node* head)
{
    return (head==NULL);
}
struct node* insert(struct node* head,int data)
{
    struct node* start=head;
    struct node* temp =newnode(data);
    if(head==NULL )
    {
        head=temp;
        temp->next=head;
    }

    else if(head->data>data)
    {
        while(start->next!=head)
        {
            start=start->next;
        }
        start->next=temp;
        temp->next = head;
        head =temp;


    }
    else{
        while(start->next != head && start->next->data<data)
        {
            start=start->next;

            //  if (start->next != NULL)

            //    start->next->prev=start;
        }
        temp->next=start->next;
          //if (start->next != NULL)
          //  start->next->next = head;
        start->next=temp;
       // temp->prev=start;
    }
return head;
}
void display(struct node* head)
{
     if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp=head;
    while(temp ->next!=head)
    {
        printf("  data %d \n",temp->data);
        temp=temp->next;
    }
    printf(" data %d \n",temp->data);
}
int main()
{
    struct node* pq=NULL;
    pq=insert(pq,15);
    // pq=insert(pq,13);
    // pq=insert(pq,10);
    // pq=insert(pq,8);
    // pq=insert(pq,1);
    display(pq);
}


