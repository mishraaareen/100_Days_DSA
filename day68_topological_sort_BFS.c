#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int topo[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    while (!isEmpty()) {
        int u = dequeue();
        topo[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("Graph contains a cycle! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}