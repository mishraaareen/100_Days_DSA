#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = preorder[*preIndex];
    node->left = node->right = NULL;
    (*preIndex)++;

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, node->data);

    node->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

struct Node* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return build(preorder, inorder, 0, n - 1, &preIndex);
}

void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct Node* root = buildTree(preorder, inorder, n);

    printInorder(root);
    return 0;
}