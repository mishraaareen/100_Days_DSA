#include <stdio.h>
#include <stdlib.h>  // for abs()

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findClosestToZero(int arr[], int n) {
    // Step 1: Sort the array
    bubbleSort(arr, n);

    int left = 0;
    int right = n - 1;

    int min_sum = arr[left] + arr[right];
    int min_left = left;
    int min_right = right;

    // Step 2: Two pointer technique
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements closest to zero are: %d and %d\n",
           arr[min_left], arr[min_right]);
}

int main() {
    int n ;
    printf("Enter size of an array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d element in an array: ",n);
    for ( int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    

    findClosestToZero(arr, n);

    return 0;
}
