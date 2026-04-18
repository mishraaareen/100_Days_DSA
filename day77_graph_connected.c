#include <stdio.h>

int n;
int adj[100][100];
int visited[100];

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(0);

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Not Connected");
            return 0;
        }
    }

    printf("Connected");
    return 0;
}