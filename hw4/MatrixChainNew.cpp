#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
long int matrixChainMultiplication(vector<int>& arr){
    int n=arr.size()/2;
    vector<vector<long int>>A(n,vector<long int>(n));
    for(int i=0;i<n;i++){
        A[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            A[i][j]=A[i][i]+A[i+1][j]+arr[2*i]*arr[2*i+1]*arr[2*j+1];
            for(int k=i;k<=j-1;k++){
                long int q=A[i][k]+A[k+1][j]+arr[2*i]*arr[2*k+1]*arr[2*j+1];
                if(q<A[i][j]){
                    A[i][j]=q;
                }
            }
        }
    }
    return A[0][n-1];
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(2*n);
    for (int i = 0; i < n; i++) {
        cin >> arr[2*i]>>arr[2*i+1];
    }
    cout << matrixChainMultiplication(arr) << endl;
    return 0;
}