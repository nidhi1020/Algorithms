#include <stdio.h>
#include <stdlib.h>

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket sort
void bucketSort(float arr[], int n) {
    // Create n buckets
    float buckets[n][n];  // each bucket can hold up to n elements
    int bucketCount[n];   // number of elements in each bucket

    for (int i = 0; i < n; i++)
        bucketCount[i] = 0;

    // Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bi = (int)(n * arr[i]); // bucket index
        buckets[bi][bucketCount[bi]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        insertionSort(buckets[i], bucketCount[i]);

    // Concatenate buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted:   ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);

    return 0;
}
