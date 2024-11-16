#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    if (!head) return nullptr;

    Node* tail = head;
    if (head->child) {
        Node* childTail = flatten(head->child);
        Node* next = head->next;
        head->next = head->child;
        head->child = nullptr;
        childTail->next = next;
        tail = next ? flatten(next) : childTail;
    } else {
        tail = head->next ? flatten(head->next) : head;
    }

    return tail;
}

Node* restructure(Node* root) {
    return flatten(root);
}

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;
    newNode->child = nullptr;
    return newNode;
}

// Function to print the restructured linked list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        Node* root = nullptr;
        Node* prev = nullptr;

        for (int i = 0; i < N; i++) {
            int u, v, type;
            cin >> u >> v >> type;

            Node* nodeU = createNode(u);
            Node* nodeV = createNode(v);

            if (!root) {
                root = nodeU;
                prev = nodeU;
            } else {
                prev->next = nodeU;
                prev = nodeU;
            }

            if (type == 0) {
                nodeU->next = nodeV;
            } else {
                nodeU->child = nodeV;
            }
        }

        Node* restructuredRoot = restructure(root);
        printList(restructuredRoot);
    }

    return 0;
}