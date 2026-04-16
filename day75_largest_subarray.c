#include <stdio.h>
#include <stdlib.h>

int maxLen(int arr[], int n) {
    int max_length = 0, sum = 0;
    int *hash = (int *)malloc(sizeof(int) * (2 * n + 1));
    for (int i = 0; i < 2 * n + 1; i++) hash[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            if (i + 1 > max_length) max_length = i + 1;
        }

        int index = sum + n;

        if (hash[index] == -2) {
            hash[index] = i;
        } else {
            int length = i - hash[index];
            if (length > max_length) max_length = length;
        }
    }

    free(hash);
    return max_length;
}

int main() {
    int arr[] = {1, -1, 3, 2, -2, -3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxLen(arr, n));
    return 0;
}