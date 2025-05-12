#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially a leaf
    return newNode;
}

// Get height of a node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Update height of a node
int max(int a, int b) {
    return (a > b) ? a : b;
}

void updateHeight(Node* node) {
    if (node != NULL) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Get balance factor of a node
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    updateHeight(root);
    return root;
}

int main() {
    int elements[] = {10, 5, 15, 3, 7, 20};
    int n = sizeof(elements) / sizeof(elements[0]);

    Node* root = NULL;

    // Build BST from array
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Calculate and print balance factor of the entire tree (root node)
    int rootBalance = getBalance(root);
    printf("Balance Factor of the BST (Root Node): %d\n", rootBalance);

    return 0;
}

