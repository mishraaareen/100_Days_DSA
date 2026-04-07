#include <stdio.h>
#include <stdlib.h>

int V;

int isCyclicUtil(int v, int **adj, int *visited, int *recStack) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i, adj, visited, recStack))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int isCyclic(int **adj) {
    int *visited = (int *)calloc(V, sizeof(int));
    int *recStack = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (isCyclicUtil(i, adj, visited, recStack))
            return 1;
    }
    return 0;
}

int main() {
    V = 4;

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        adj[i] = (int *)calloc(V, sizeof(int));

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;
    adj[2][3] = 1;

    if (isCyclic(adj))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}