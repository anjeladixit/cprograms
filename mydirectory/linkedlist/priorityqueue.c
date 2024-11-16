#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct Queue {
    struct node *front, *rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;

    struct node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}void display(struct Queue* q) {
    struct node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void priority(struct Queue* q)
{ struct node* temp = q->front;

  if(temp->data>temp->next->data)
{
    int new =temp->data;
    temp->data=temp->next->data;
    temp->next->data=new;
  
}
    
}
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 40);
    enqueue(q, 30);
    enqueue(q, 20);

    printf("Queue: ");
    display(q);
    priority(q);
    display(q);

    return 0;
}
