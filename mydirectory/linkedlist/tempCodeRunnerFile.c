#include<stdio.h>
#include<stdlib.h>
struct node{
    int row;
    int col;
    int value;
    struct node* next;
};
struct node * create(int row,int col,int value)
{
    struct node* newp=(struct node*)malloc(sizeof(struct node));
    newp->col=col;
    newp->row=row;
    newp->value=value;
    newp->next=NULL;
    return newp;
}
struct node* insert(struct node* head,int row,int col,int value)
{
    struct node* newnode=create(row,col,value);
    struct node* previous=NULL;
    struct node* current =head;
    while(current!=NULL || current->row<row||(current->row==row && current->col<col))
    {
        previous=current;
        current=current->next;
    }
    if(previous==NULL)
    {
        newnode->next=head;
        head=newnode;

    }
    else
    {
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
for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
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
   matrix= insert(matrix, 0, 0, 8);
   matrix= insert(matrix, 1, 1, 6);
   matrix= insert(matrix, 1, 2, 5);
   matrix= insert(matrix, 2, 3, 9);
    matrix= insert(matrix, 3, 2, 7);

   displaySparseMatrix(matrix);
   
   
   
}