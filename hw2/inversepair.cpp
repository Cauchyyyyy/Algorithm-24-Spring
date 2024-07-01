#include <stdio.h>
#include <stdlib.h>

int merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return count;
}

int mergeSort(int *arr, int *temp, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    int count = mergeSort(arr, temp, left, mid) + mergeSort(arr, temp, mid + 1, right);
    count += merge(arr, temp, left, mid, right);
    return count;
}

int main() {
    int n;
    scanf("%d\n9", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", mergeSort(arr, temp, 0, n - 1));
    free(arr);
    free(temp);
    return 0;
}
