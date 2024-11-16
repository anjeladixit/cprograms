#include <stdio.h>
#include <stdlib.h>

#define MAX 3    // Max degree of the B-tree node
#define MIN 2    // Minimum degree

struct BTreeNode {
    int keys[MAX];
    struct BTreeNode *child[MAX + 1];
    int n;            // Current number of keys
    int leaf;         // Whether this is a leaf node
};

// Function to create a new B-tree node
struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->leaf = leaf;
    newNode->n = 0;
    for (int i = 0; i < MAX + 1; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

// Split child node
void splitChild(struct BTreeNode* x, int i) {
    struct BTreeNode* y = x->child[i];
    struct BTreeNode* z = createNode(y->leaf);
    z->n = MIN - 1;

    for (int j = 0; j < MIN - 1; j++) {
        z->keys[j] = y->keys[j + MIN];
    }

    if (!y->leaf) {
        for (int j = 0; j < MIN; j++) {
            z->child[j] = y->child[j + MIN];
        }
    }

    y->n = MIN - 1;

    for (int j = x->n; j >= i + 1; j--) {
        x->child[j + 1] = x->child[j];
    }

    x->child[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }

    x->keys[i] = y->keys[MIN - 1];
    x->n++;
}

// Insert non-full node
void insertNonFull(struct BTreeNode* x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }

        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && k < x->keys[i]) {
            i--;
        }
        i++;

        if (x->child[i]->n == MAX - 1) {
            splitChild(x, i);

            if (k > x->keys[i]) {
                i++;
            }
        }
        insertNonFull(x->child[i], k);
    }
}

// Insert into B-Tree
void insert(struct BTreeNode** root, int k) {
    struct BTreeNode* r = *root;
    if (r->n == MAX - 1) {
        struct BTreeNode* s = createNode(0);
        s->child[0] = r;
        splitChild(s, 0);

        int i = 0;
        if (s->keys[0] < k) {
            i++;
        }
        insertNonFull(s->child[i], k);
        *root = s;
    } else {
        insertNonFull(r, k);
    }
}

// Traverse B-Tree
void traverse(struct BTreeNode* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf) {
            traverse(root->child[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf) {
        traverse(root->child[i]);
    }
}

// Main function
int main() {
    struct BTreeNode* root = createNode(1);
    int numElements, value;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insert(&root, value);
    }

    printf("B-tree traversal: ");
    traverse(root);
    printf("\n");

    return 0;
}
