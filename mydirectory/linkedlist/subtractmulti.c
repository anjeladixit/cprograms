#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to get the length of the linked list
int getListLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to compare two linked lists (returns 1 if first > second, -1 if first < second, 0 if equal)
int compareLists(Node* first, Node* second) {
    int len1 = getListLength(first);
    int len2 = getListLength(second);

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    // If lengths are equal, compare digit by digit
    while (first != NULL && second != NULL) {
        if (first->data > second->data) return 1;
        if (first->data < second->data) return -1;
        first = first->next;
        second = second->next;
    }

    return 0;
}

// Function to subtract two linked lists representing large numbers
Node* subtractLists(Node* first, Node* second) {
    Node* result = NULL;
    int borrow = 0;

    // Traverse both lists
    while (first != NULL) {
        int firstDigit = first->data;
        int secondDigit = (second != NULL) ? second->data : 0;

        // Calculate the difference with borrow
        int diff = firstDigit - secondDigit - borrow;

        // Handle borrowing
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        // Append the result digit to the result list
        appendNode(&result, diff);

        // Move to the next digits
        first = first->next;
        if (second != NULL) {
            second = second->next;
        }
    }

    // Remove leading zeros in the result (if any)
    Node* current = result;
    Node* prev = NULL;

    while (current != NULL && current->data == 0) {
        prev = current;
        current = current->next;
        free(prev);
    }

    // If result is NULL after removing leading zeros, it means the result is zero
    if (current == NULL) {
        return createNode(0);
    }

    return current;
}

// Function to print the linked list in reverse order (to display the correct number)
void printList(Node* head) {
    if (head == NULL) return;
    printList(head->next);
    printf("%d", head->data);
}

// Main function to test the subtraction
int main() {
    Node* first = NULL;
    Node* second = NULL;

    // Example numbers: 567 - 1234
    // These numbers should be stored in reverse order in the linked list for easy computation.
    appendNode(&first, 4);
    appendNode(&first, 3);
    appendNode(&first, 2);
    // appendNode(&first, 1);

    appendNode(&second, 7);
    appendNode(&second, 6);
    appendNode(&second, 5);

    printf("First Number: ");
    printList(first);
    printf("\n");

    printf("Second Number: ");
    printList(second);
    printf("\n");

    // Check which number is larger and swap if necessary
    int comparison = compareLists(first, second);
    int isNegative = 0;
    
    if (comparison == 0) {
        printf("Result: 0\n");
        return 0;
    } else if (comparison < 0) {
        // If the first number is smaller than the second, swap them
        Node* temp = first;
        first = second;
        second = temp;
        isNegative = 1;
    }

    // Perform subtraction
    Node* result = subtractLists(first, second);

    // Print the result, handling negative sign
    if (isNegative) {
        printf("Result (after subtraction): -");
    } else {
        printf("Result (after subtraction): ");
    }
    
    printList(result);
    printf("\n");

    return 0;
}
