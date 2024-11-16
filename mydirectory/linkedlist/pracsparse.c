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
    while(current!=NULL &&( current->row<row||(current->row==row && current->col<col)))
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
// void displaySparseMatrix2(struct node* head,int r,int c) {
//      struct node* temp = head;
//     printf("Row\tCol\tValue\n");
//     while (temp != NULL) {
//         if ( temp->row == r && temp->col == c) {
//                 printf("%d 1, ", temp->value);
//                     temp=temp->next;
//             if(temp->col>c && temp->row==r)
//             {
//                 printf("%d 3 ,", temp->value);
//                 temp=temp->next;
//             }
//              else if(temp->row>r)
//             {
//                 printf("%d 1, ", temp->value);
//                 temp=temp->next;
//             }
//              else if(temp->row<r )
//             {
//                 printf("%d 3 ,", temp->value);
//                 temp=temp->next;
//             }
//              else if(temp->row==r && temp->col<c)
//             {
//                 printf("%d 4 ,", temp->value);
//                 temp=temp->next;
//             }

//             }
//             else temp=temp->next;
        
            


        
//     }

//   }\


// void displaySparseMatrix2(struct node* head, int r, int c) {
//     struct node* temp = head;

//     // Print value at (r, c)
//     while (temp != NULL) {
//         if (temp->row == r && temp->col == c) {
//             printf("Value at (%d, %d): %d\n", r, c, temp->value);
//             break;  // Exit the loop after finding the value at (r, c)
//         }
//         temp = temp->next;
//     }

//     temp = head; // Reset pointer to head for surrounding elements

//     // Print values around (r, c)
//     while (temp != NULL) {
//         if (temp->row == r && temp->col == c + 1) {
//             printf("Right of (%d, %d): %d\n", r, c, temp->value);
//         }
//         else if (temp->row == r && temp->col == c - 1) {
//             printf("Left of (%d, %d): %d\n", r, c, temp->value);
//         }
//         else if (temp->row == r + 1 && temp->col == c) {
//             printf("Below (%d, %d): %d\n", r, c, temp->value);
//         }
//         else if (temp->row == r - 1 && temp->col == c) {
//             printf("Above (%d, %d): %d\n", r, c, temp->value);
//         }
//         temp = temp->next;
//     }
// }


void displaySparseMatrix2(struct node* head, int r, int c) {
    struct node* temp = head;
    int left = 0, right = 0, up = 0, down = 0, center = 0;

    // Traverse the list to find (r, c) and its neighbors
    while (temp != NULL) {
        if (temp->row == r && temp->col == c) {
            center = temp->value; // Value at (r, c)
        }
        else if (temp->row == r && temp->col == c - 1) {
            left = temp->value;  // Value at (r, c-1)
        }
        else if (temp->row == r && temp->col == c + 1) {
            right = temp->value;  // Value at (r, c+1)
        }
        else if (temp->row == r - 1 && temp->col == c) {
            up = temp->value;  // Value at (r-1, c)
        }
        else if (temp->row == r + 1 && temp->col == c) {
            down = temp->value;  // Value at (r+1, c)
        }
        temp = temp->next; // Move to the next node
    }

    // Print the values in a structured manner
    printf("Value at (%d, %d): %d\n", r, c, center);
    if (left != 0) printf("Left of (%d, %d): %d\n", r, c, left);
    if (right != 0) printf("Right of (%d, %d): %d\n", r, c, right);
    if (up != 0) printf("Above (%d, %d): %d\n", r, c, up);
    if (down != 0) printf("Below (%d, %d): %d\n", r, c, down);
}



int main()

{   struct node* matrix=NULL;
   matrix= insert(matrix, 0, 0, 8);
   matrix= insert(matrix, 1, 1, 6);
   matrix= insert(matrix, 1, 2, 5);
   matrix= insert(matrix, 2, 3, 9);
    matrix= insert(matrix, 3, 2, 7);

   displaySparseMatrix(matrix);
   
      displaySparseMatrix2(matrix,1,1);
   
}