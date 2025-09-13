#include <stdio.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i];

    int count[50] = {0};   // assuming max <= 50 for simplicity
    int output[n];

    // Count frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Build sorted array
    int k = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            output[k++] = i;
            count[i]--;
        }
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    countingSort(arr, n);

    printf("\nSorted:   ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}
