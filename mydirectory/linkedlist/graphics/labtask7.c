#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct node* inorderSuccessor(struct node* root, struct node* node) {
    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL)
            node = node->left;
        return node;
    }
    struct node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }

    return successor;
}

int main() {
    struct node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);
    struct node* node = root->left; 
    struct node* successor = inorderSuccessor(root, node);

    if (successor != NULL)
        printf("Inorder successor of %d is %d\n", node->data, successor->data);
    else
        printf("Inorder successor of %d does not exist\n", node->data);

    return 0;
}
