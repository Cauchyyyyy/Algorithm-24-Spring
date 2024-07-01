#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 获取数组中的最大值
int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// 对数组按照指定的位数进行计数排序
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // 输出数组
    int count[10] = {0};

    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // 计算小于等于当前数字的数字个数
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // 将数字放到正确的位置上
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将排序后的结果复制回原数组
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// 基数排序函数
void radixsort(vector<int>& arr) {
    // 找到数组中的最大值
    int maxVal = getMax(arr);

    // 从最低位开始，依次对每一位进行计数排序
    for (int exp = 1; maxVal / exp > 0; exp *= 10){
        countSort(arr, exp);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    radixsort(arr);
    
    cout << arr[k-1] << endl;
    return 0;
}