#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

int isMinHeap(struct Node* root) {
    
    if (root->left == NULL && root->right == NULL)
        return 1;

   
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

  
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

int checkMinHeap(struct Node* root) {
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) &&
        isMinHeap(root))
        return 1;

    return 0;
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);

    if (checkMinHeap(root))
        printf("The binary tree is a Min Heap\n");
    else
        printf("The binary tree is NOT a Min Heap\n");

    return 0;
}