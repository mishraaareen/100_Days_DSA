#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int V = 5, E = 8, src = 0;
    struct Edge edges[] = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},
        {1,4,2},{3,2,5},{3,1,1},{4,3,-3}
    };

    int dist[V];
    for(int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected\n");
            return 0;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}