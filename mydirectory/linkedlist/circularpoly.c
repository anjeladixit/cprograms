#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* create(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;

}
struct node* insert(struct node* head,int data)
{
    struct node* newnode=create(data);
    struct node* temo
}