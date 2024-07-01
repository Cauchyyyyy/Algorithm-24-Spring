#include <iostream>
using namespace std;
#include <vector>

long int matrixChainMultiplication(vector<int> arr, int i, int j) {
    long int times=0;
    if(i==j){
        times=0;
    }
    else{
        times=matrixChainMultiplication(arr,i,i)+matrixChainMultiplication(arr,i+1,j)+arr[2*i]*arr[2*i+1]*arr[2*j+1];
        for(int k=i;k<j;k++){            
            long int temp=matrixChainMultiplication(arr ,i,k)+matrixChainMultiplication(arr,k+1,j)+arr[2*i]*arr[2*k+1]*arr[2*j+1];
            if(times>temp){
                times=temp;
            }
        }
    }
    return times;
}
int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(2*n);
    for (int i = 0; i < n; i++) {
        cin >> arr[2*i]>>arr[2*i+1];
    }
    cout << matrixChainMultiplication(arr, 0,n-1) << endl;
}

