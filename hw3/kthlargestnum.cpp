#include <stdio.h>
#include <stdlib.h>

// Swap function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to partition the array around a pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) { // Change this condition for k-th largest
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quickselect function to find the k-th largest element
int quickselect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pi = partition(arr, low, high);
        if (pi == k) // If the pivot is at the k-th position, return it
            return arr[pi];
        else if (pi < k) // If k is to the right of the pivot, search in the right subarray
            return quickselect(arr, pi + 1, high, k);
        else // If k is to the left of the pivot, search in the left subarray
            return quickselect(arr, low, pi - 1, k);
    }
    return arr[low]; // Return the element at the low index if low equals high
}

int main() {
    int n; // size of array
    
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int)); // dynamically allocate memory for array
    int k; // k-th largest element
    
    scanf("%d", &k);
    // Input array elements
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    

    // Call quickselect function to find the k-th largest element
    int kth_largest = quickselect(arr, 0, n - 1, k-1);

    printf("%d\n",  kth_largest);

    free(arr); // free dynamically allocated memory

    return 0;
}
