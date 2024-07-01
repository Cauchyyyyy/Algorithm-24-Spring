#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long merge(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    long count = 0;
    vector<int> temp(right - left + 1);
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } 
        else {
            temp[k] = arr[j];
            j++;
            count += mid - i + 1;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];k++;i++;
    }
    while (j <= right) {
        temp[k] = arr[j];k++;j++;
    }
    for  (int l = 0; l < temp.size(); l++) {
        arr[left + l] = temp[l];
    }
    return count;
}

long mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = floor((right + left) / 2);
    long count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);
    return count;
}

int main() {
    int n=0;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long m=mergeSort(arr, 0, n - 1);
    cout <<m<< endl;
    
    return 0;
}
