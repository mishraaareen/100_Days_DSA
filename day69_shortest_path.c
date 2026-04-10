#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int v, w;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} AdjList;

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode arr[MAX];
    int size;
} MinHeap;

AdjList graph[MAX];
int dist[MAX];

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap *h, int i) {
    int l, r, smallest;
    while (1) {
        l = 2 * i + 1;
        r = 2 * i + 2;
        smallest = i;
        if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
            smallest = l;
        if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
            smallest = r;
        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
}

void push(MinHeap *h, int node, int distv) {
    h->arr[h->size].node = node;
    h->arr[h->size].dist = distv;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap *h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

void addEdge(int u, int v, int w) {
    int idx = graph[u].size++;
    graph[u].edges[idx].v = v;
    graph[u].edges[idx].w = w;
}

void dijkstra(int n, int src) {
    MinHeap h;
    h.size = 0;
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    push(&h, src, 0);
    while (h.size) {
        HeapNode cur = pop(&h);
        int u = cur.node;
        if (cur.dist > dist[u]) continue;
        for (int i = 0; i < graph[u].size; i++) {
            int v = graph[u].edges[i].v;
            int w = graph[u].edges[i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) graph[i].size = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    int src;
    scanf("%d", &src);
    dijkstra(n, src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    return 0;
}