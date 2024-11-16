#include<stdio.h>
#include<stdlib.h>
struct node {
   int row;
   int col;
   int value;
   struct node* next;
};
struct node* create(int row,int col,int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->row=row;
    temp->col=col;
    temp->value=value;
    temp->next=NULL;
    return temp;
}
struct node* insert(struct node* head,int row,int col,int value)
{
    struct node* newnode=create(row,col,value);
    struct node* previous=NULL;
    struct node* current=head;
    while(current!=NULL && (current->row<row||(current->row==row && current->col<col)) )
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
struct node* transpose(struct node* head){
    struct node* transposematrix=NULL;
    struct node* current=head;
    while(current!=NULL)
    {
        transposematrix=insert(transposematrix,current->col,current->row,current->value);
        current=current->next;
    }
 return transposematrix;
}
struct node* addtwo(struct node* l1,struct node* l2)
{  struct node* head1=l1;
   struct node* head2=l2;
    struct node* addlist=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->row==head2->row && head1->col==head2->col )
        {
            addlist=insert(addlist,head1->row,head1->col,head1->value+head2->value);
            head1=head1->next;
            head2=head2->next;
        }
        else if (head1->row < head2->row || (head1->row == head2->row && head1->col < head2->col)) {
            addlist = insert(addlist, head1->row, head1->col, head1->value);
            head1 = head1->next;
        } 
    else {
            addlist = insert(addlist, head2->row, head2->col, head2->value);
            head2 = head2->next;
        }

    }
     while (head1 != NULL) {
        addlist = insert(addlist, head1->row, head1->col, head1->value);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        addlist = insert(addlist, head2->row, head2->col, head2->value);
        head2 = head2->next;
    }

    
    return addlist;
}
struct node* multiplySparseMatrices(struct node* matrix1, struct node* matrix2) {
    if (!matrix1 || !matrix2) return NULL;

    struct node* result = NULL;
    struct node* row = matrix1;
    while (row) {
        struct node* col = matrix2;
        while (col) {
            if (row->col == col->row) {
                int newrow=row->row;
                int newcol=col->col;
                int newvalue=row->value*col->value;
                struct node* current=result;
                while(current!=NULL &&(current->row!=newrow || current->col!=newcol))
                {
                    current=current->next;
                }
                if(current==NULL)
                {result = insert(result, newrow, newcol, newvalue);}
                else{
                    current->value+=newvalue;
                }
            }
            col = col->next;
        }
        row = row->next;
    }

    return result;
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
   struct node* transposematrix=NULL;
  struct node* addlist=NULL;
  struct node* mul=NULL;
   matrix= insert(matrix, 0, 0, 8);
   matrix= insert(matrix, 1, 1, 6);
   matrix= insert(matrix, 1, 2, 5);
   matrix= insert(matrix, 2, 3, 9);
    matrix= insert(matrix, 3, 2, 7);

   displaySparseMatrix(matrix);
   
   
   
}