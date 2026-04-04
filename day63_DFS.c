#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n; // number of vertices

// DFS function
void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);

    return 0;
}