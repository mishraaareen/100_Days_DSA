#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int size(struct Queue* q) {
    return q->rear - q->front;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(&q);

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

void rightView(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int levelSize = size(&q);

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = dequeue(&q);

            if (i == levelSize - 1)
                printf("%d ", curr->data);

            if (curr->left)
                enqueue(&q, curr->left);
            if (curr->right)
                enqueue(&q, curr->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    rightView(root);

    return 0;
}