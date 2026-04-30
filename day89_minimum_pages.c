#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;
        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
            if (students > m) return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;
    int low = 0, high = 0, res = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, m, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;
    printf("%d\n", allocateBooks(arr, n, m));
    return 0;
}