#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int row;
    int col;
    int value;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int row, int col, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in the linked list in sorted order
struct node*  insertSorted(struct node* head, int row, int col, int value) {
    struct node* newNode = createNode(row, col, value);
    
    if (head == NULL || head->row > row || ((head)->row == row && (head)->col > col)) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node* current = head;
        while (current->next != NULL && (current->next->row < row || (current->next->row == row && current->next->col < col))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to multiply two sparse matrices represented as linked lists
// struct Node* multiplySparseMatrices(struct Node* mat1, struct Node* mat2) {
//     struct Node* result = NULL;

//     // Traverse through each element in mat1
//     struct Node* p = mat1;
//     while (p != NULL) {
//         struct Node* q = mat2;
//         while (q != NULL) {
//             if (p->col == q->row) {  // Ensure valid multiplication indices
//                 int newRow = p->row;
//                 int newCol = q->col;
//                 int newValue = p->value * q->value;

//                 // Search if (newRow, newCol) already exists in the result
//                 struct Node* current = result;
//                 struct Node* prev = NULL;
//                 while (current != NULL && (current->row != newRow || current->col != newCol)) {
//                     prev = current;
//                     current = current->next;
//                 }

//                 if (current == NULL) {
//                     // Insert new entry in result if not present
//                     insertSorted(&result, newRow, newCol, newValue);
//                 } else {
//                     // Update existing entry
//                     current->value += newValue;
//                 }
//             }
//             q = q->next;
//         }
//         p = p->next;
//     }

//     return result;
// }


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
                {result = insertSorted(result, newrow, newcol, newvalue);}
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


// Function to print the sparse matrix
void printSparseMatrix(struct node* head) {
    struct node* current = head;
    printf("Row\tCol\tValue\n");
    while (current != NULL) {
        printf("%d\t%d\t%d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

// // Function to free the linked list
// void freeList(struct Node* head) {
//     struct Node* current = head;
//     while (current != NULL) {
//         struct Node* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

int main() {
    // Example sparse matrix 1: 3x3
    struct node* mat1 = NULL;
   mat1=insertSorted(mat1, 0, 0, 1);
   mat1= insertSorted(mat1, 1, 1, 2);
   mat1= insertSorted(mat1, 0, 2, 3);

    // Example sparse matrix 2: 3x3
    struct node* mat2 = NULL;
   mat2= insertSorted(mat2, 0, 0, 4);
   mat2= insertSorted(mat2, 0, 1, 5);
   mat2= insertSorted(mat2, 2, 1, 6);
mat2= insertSorted(mat2, 2, 0, 2);
    printf("Matrix 1:\n");
    printSparseMatrix(mat1);

    printf("\nMatrix 2:\n");
    printSparseMatrix(mat2);

   struct node* product=NULL;
   product=multiplySparseMatrices(mat1,mat2);
   printf("product \n");
   printSparseMatrix(product);
    
}
