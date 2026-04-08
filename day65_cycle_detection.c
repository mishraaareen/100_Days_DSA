#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int *visited, int **adj, int *sizes) {
    visited[v] = 1;
    for (int i = 0; i < sizes[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u, v, visited, adj, sizes)) return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int hasCycle(int n, int **adj, int *sizes) {
    int *visited = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, sizes)) {
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
}

int main() {
    int n = 5;
    int sizes[] = {2, 2, 2, 1, 1};

    int **adj = malloc(n * sizeof(int*));

    adj[0] = malloc(2 * sizeof(int));
    adj[0][0] = 1; adj[0][1] = 2;

    adj[1] = malloc(2 * sizeof(int));
    adj[1][0] = 0; adj[1][1] = 2;

    adj[2] = malloc(2 * sizeof(int));
    adj[2][0] = 0; adj[2][1] = 1;

    adj[3] = malloc(1 * sizeof(int));
    adj[3][0] = 4;

    adj[4] = malloc(1 * sizeof(int));
    adj[4][0] = 3;

    if (hasCycle(n, adj, sizes))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    return 0;
}
