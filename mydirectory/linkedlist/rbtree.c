#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct Node {
    int data;
    int color; // 0 for RED, 1 for BLACK
    struct Node *left, *right, *parent;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Perform a left rotation
void rotateLeft(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Perform a right rotation
void rotateRight(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

// Fix the red-black tree after insertion
void fixViolation(struct Node** root, struct Node* newNode) {
    struct Node *parent = NULL, *grandparent = NULL;

    while ((newNode != *root) && (newNode->color == RED) && (newNode->parent->color == RED)) {
        parent = newNode->parent;
        grandparent = newNode->parent->parent;

        // Case A: Parent is left child of grandparent
        if (parent == grandparent->left) {
            struct Node* uncle = grandparent->right;

            // Case 1: Uncle is red
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
                // Case 2: newNode is right child
                if (newNode == parent->right) {
                    rotateLeft(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }

                // Case 3: newNode is left child
                rotateRight(root, grandparent);
                int tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                newNode = parent;
            }
        } else {
            // Case B: Parent is right child of grandparent
            struct Node* uncle = grandparent->left;

            // Case 1: Uncle is red
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            } else {
                // Case 2: newNode is left child
                if (newNode == parent->left) {
                    rotateRight(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }

                // Case 3: newNode is right child
                rotateLeft(root, grandparent);
                int tempColor = parent->color;
                parent->color = grandparent->color;
                grandparent->color = tempColor;
                newNode = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

// Insert a new node into the red-black tree
void insert(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        newNode->color = BLACK;
        *root = newNode;
    } else {
        struct Node* current = *root;
        struct Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;
        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        fixViolation(root, newNode);
    }
}

// Inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    int numElements, value;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("Inorder traversal of the Red-Black Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
