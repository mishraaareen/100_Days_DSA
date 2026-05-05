#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

Interval* mergeIntervals(Interval arr[], int n, int *returnSize) {
    qsort(arr, n, sizeof(Interval), cmp);

    Interval *res = (Interval *)malloc(n * sizeof(Interval));
    int idx = 0;

    res[idx] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= res[idx].end) {
            if (arr[i].end > res[idx].end)
                res[idx].end = arr[i].end;
        } else {
            idx++;
            res[idx] = arr[i];
        }
    }

    *returnSize = idx + 1;
    return res;
}

int main() {
    Interval arr[] = {{1,3},{2,6},{8,10},{15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int size;

    Interval *res = mergeIntervals(arr, n, &size);

    for (int i = 0; i < size; i++)
        printf("%d %d\n", res[i].start, res[i].end);

    free(res);
    return 0;
}