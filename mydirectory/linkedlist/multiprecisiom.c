#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digit;            // Store the digit (0-9)
    struct Node *next;   // Pointer to the next node
} Node;
// Function to create a new node with a given digit
Node* createNode(int digit) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a linked list from a string representing a number
Node* initList(const char *number) {
    Node *head = NULL, *tail = NULL;

    for (int i = 0; number[i] != '\0'; i++) {
        int digit = number[i] - '0'; // Convert char to int
        Node *newNode = createNode(digit);
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            // tail->next = newNode;
            // tail = newNode;
            newNode->next=head;
            head=newNode;
        }
    }

    return head;
}
// Function to print the linked list
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->digit);
        current = current->next;
    }
    printf("\n");
}
Node* addLists(Node *l1, Node *l2) {
    Node *result = NULL, *tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->digit;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->digit;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        Node *newNode = createNode(sum);
        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}
Node* multiplyLists(Node *l1, Node *l2) {
    Node *result = NULL;
    Node *l1Curr, *l2Curr, *tempResult, *tempTail;

    int pos1 = 0, pos2 = 0;

    // Traverse first list
    for (l1Curr = l1; l1Curr != NULL; l1Curr = l1Curr->next) {
        int carry = 0;
        int l1Digit = l1Curr->digit;
        Node *temp = NULL;

        // Traverse second list
        for (l2Curr = l2; l2Curr != NULL; l2Curr = l2Curr->next) {
            int product = l1Digit * l2Curr->digit + carry;
            carry = product / 10;
            product = product % 10;

            // Append product digit to temp list
            if (temp == NULL) {
                temp = createNode(product);
                tempTail = temp;
            } else {
                tempTail->next = createNode(product);
                tempTail = tempTail->next;
            }
        }
        
        if (carry) {
            tempTail->next = createNode(carry);
        }

        // Add temp to the result
        result = addLists(result, temp);
        pos1++;
    }

    return result;
}
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    Node *num1 = initList("12345");
    Node *num2 = initList("6789");
    
    printf("Number 1: ");
    printList(num1);
    printf("Number 2: ");
    printList(num2);
    
    Node *sum = addLists(num1, num2);
    printf("Sum: ");
    printList(sum);
    
    Node *product = multiplyLists(num1, num2);
    printf("Product: ");
    printList(product);
    
    // Free memory
    freeList(num1);
    freeList(num2);
    freeList(sum);
    freeList(product);

    return 0;
}
