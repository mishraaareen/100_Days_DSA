#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure using linked list
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Enqueue function: Adds an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    
    // If queue is empty, set both front and rear to the new node
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    // Otherwise, add the new node to the rear and update rear pointer
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Dequeue function: Removes and returns the front element of the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1; // Indicates an empty queue
    }

    // Get the front node and move the front pointer
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    // If front is NULL after dequeue, set rear to NULL (queue becomes empty)
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

// Peek function: Returns the front element without removing it
int peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1; // Indicates an empty queue
    }
    return queue->front->data;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to print the queue (for debugging)
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the Queue implementation
int main() {
    Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Queue after enqueue operations: ");
    printQueue(queue);

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Print the queue after dequeues
    printf("Queue after dequeue operations: ");
    printQueue(queue);

    // Peek at the front element
    printf("Front element: %d\n", peek(queue));

    // Check if the queue is empty
    printf("Is queue empty? %d\n", isEmpty(queue));

    return 0;
}