#include<stdio.h>
#include<stdlib.h>
struct node{
    int ex;
    int co;
    struct node* next;
};
struct node* create(int ex,int co)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->co=co;
    newnode->ex=ex;
    newnode->next=NULL;
    return newnode;
}
struct node* insert(struct node* head,int co,int ex)
{ struct node* newnode=create(ex,co);
    if(head==NULL)
    {  
        head=newnode;
        return head;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;

}
struct node* polyadd(struct node* poly1,struct node* poly2)
{

 struct node* result = NULL;
    struct node* temp1 = poly1;
    struct node* temp2 = poly2;

    while (temp1 && temp2) {
        if (temp1->ex > temp2->ex) {
            result = insert(result, temp1->co, temp1->ex);
            temp1 = temp1->next;
        } else if (temp1->ex < temp2->ex) {
            result = insert(result, temp2->co, temp2->ex);
            temp2 = temp2->next;
        } else {
            result = insert(result, temp1->co + temp2->co, temp1->ex);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1) {
        result = insert(result, temp1->co, temp1->ex);
        temp1 = temp1->next;
    }

    while (temp2) {
        result = insert(result, temp2->co, temp2->ex);
        temp2 = temp2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct node* head) {
    struct node* temp = head;
    if (!head) return;
    while (temp) {
        printf("%dx^%d ", temp->co, temp->ex);
        temp = temp->next;
        if (temp) printf("+ ");
    }
    printf("\n");
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;

    // Polynomial 1: 3x^2 + 4x + 5
    poly1 = insert(poly1, 3, 2);
    poly1 = insert(poly1, 4, 1);
    poly1 = insert(poly1, 5, 0); // Polynomial x^3 + 2x^2 + 1
    poly2 = insert(poly2, 4, 3);
    poly2 = insert(poly2, 2, 2);
    poly2 = insert(poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = polyadd(poly1, poly2);

    printf("Resultant Polynomial after subtraction: ");
    displayPolynomial(result);

    return 0;
}