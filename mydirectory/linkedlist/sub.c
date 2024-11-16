#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int coeff;
    int exp;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node into the doubly linked list
struct Node* insertNode(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (!head) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to subtract two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    while (temp1 && temp2) {
        if (temp1->exp > temp2->exp) {
            result = insertNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            result = insertNode(result, -temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            result = insertNode(result, temp1->coeff - temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1) {
        result = insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2) {
        result = insertNode(result, -temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    if (!head) return;
    while (temp) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp) printf("+ ");
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Polynomial 1: 3x^2 + 4x + 5
    poly1 = insertNode(poly1, 3, 2);
    poly1 = insertNode(poly1, 4, 1);
    poly1 = insertNode(poly1, 5, 0);

    // Polynomial 2: 4x^3 + 2x^2 + 1
    poly2 = insertNode(poly2, 4, 3);
    poly2 = insertNode(poly2, 2, 2);
    poly2 = insertNode(poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = subtractPolynomials(poly1, poly2);

    printf("Resultant Polynomial after subtraction: ");
    displayPolynomial(result);

    return 0;
}
