#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include <cmath>
using namespace std;
//right but too long time


long int partition(vector<long int>& nums, long int left, long int right,long int pivot) {
    if (left == right) {
        return left;
    }
    long int t=left;
    
    long int i = left - 1;
    for (long int j = left; j <= right; j++) {
        if (nums[j] > pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
        if(nums[j] == pivot) {
            t=j;
        }
    }
    swap(nums[i + 1], nums[t]);
    return i + 1;
}

long int findKthLargest(vector<long int>& nums, long p,long r,long int i) {
    while((r-p+1)%5!=0){
        for(int j=p+1;j<=r;j++){
            if(nums[j]>nums[p]){
                swap(nums[j],nums[p]);
            }
        }
        if(i==1){
            return nums[p];
        }
        p++;i--;
    }
    long g=(r-p+1)/5;
    for(int j=p;j<=p+g-1;j++){
        long int temp[5]={nums[j],nums[j+g],nums[j+2*g],nums[j+3*g],nums[j+4*g]};
        sort(temp,temp+5);
        nums[j]=temp[4];
        nums[j+g]=temp[3];
        nums[j+2*g]=temp[2];
        nums[j+3*g]=temp[1];
        nums[j+4*g]=temp[0];
    }
    long x=findKthLargest(nums,p+2*g,p+3*g,floor(g/2)+1);
    long q=partition(nums,p,r,x);
    long k=q-p+1;
    if(i==k)    return nums[q];
    else if(i<k){
        return findKthLargest(nums,p,q-1,i);
    }
    else{
        return findKthLargest(nums,q+1,r,i-k);
    }
}

int main() {
    long int n, k;
    cin >> n >> k;
    vector<long int> a(n);
    for (long int i = 0; i < n; i++) {
        cin >> a[i];
    }
    nth_element(a.begin(), a.begin() + k - 1, a.end(), greater<int>());
    cout << a[k-1] << endl;
    return 0;
}
