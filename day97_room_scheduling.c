#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

typedef struct {
    int *arr;
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i && h->arr[(i - 1) / 2] > h->arr[i]) {
        swap(&h->arr[(i - 1) / 2], &h->arr[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap *h, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < h->size && h->arr[l] < h->arr[smallest])
        smallest = l;
    if (r < h->size && h->arr[r] < h->arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int val) {
    h->arr[h->size] = val;
    heapifyUp(h, h->size);
    h->size++;
}

int pop(MinHeap *h) {
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int top(MinHeap *h) {
    return h->arr[0];
}

int minMeetingRooms(Interval intervals[], int n) {
    qsort(intervals, n, sizeof(Interval), cmpStart);

    MinHeap h;
    h.arr = (int *)malloc(n * sizeof(int));
    h.size = 0;

    push(&h, intervals[0].end);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= top(&h))
            pop(&h);
        push(&h, intervals[i].end);
    }

    int result = h.size;
    free(h.arr);
    return result;
}

int main() {
    Interval intervals[] = {{0,30},{5,10},{15,20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    printf("%d\n", minMeetingRooms(intervals, n));

    return 0;
}