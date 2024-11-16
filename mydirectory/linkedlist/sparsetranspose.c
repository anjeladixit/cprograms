#include<stdio.h>
#include<stdlib.h>
struct node {
   int row;
   int col;
   int value;
   struct node* next;
};
struct node* create(int col,int  row,int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->row=col;
    temp->col=row;
    temp->value=value;
    temp->next=NULL;
    return temp;
}
struct node* insert(struct node* head,int row,int col,int value)
{
    struct node* newnode=create(col,row,value);
    struct node* previous=NULL;
    struct node* current=head;
    while(current!=NULL && (current->row<col||(current->row==col && current->col<row)) )
    {
        previous=current;
        current=current->next;
    }
    if(previous==NULL)
    {
      newnode->next=head;
      head=newnode;
    }
    else{
        previous->next=newnode;
        newnode->next=current;
    }
  return head;
}
void displaySparseMatrix(struct node* head) {
    struct node* temp = head;
    // printf("Row\tCol\tValue\n");
    // while (temp != NULL) {
    //     printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
    //     temp = temp->next;
    // }
 for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (temp != NULL && temp->row == i && temp->col == j) {
                printf("%d ", temp->value);
                temp = temp->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}


int main()

{   struct node* matrix=NULL;
  
   matrix= insert(matrix, 0, 1, 5);
   matrix= insert(matrix, 1, 2, 8);
   matrix= insert(matrix, 2, 0, 3);
   matrix= insert(matrix, 3, 3, 6);
   matrix= insert(matrix, 1, 1, 4);
   
   displaySparseMatrix(matrix);

   
}