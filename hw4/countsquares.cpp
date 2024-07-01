#include<iostream>
#include<vector>
using namespace std;

int countSquares(vector<vector<int>>& A) {
    int n = A.size(), m = A[0].size();
    int t=min(n,m);

    //dp stored the largest square(all 0) ending at (i,j)
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1 - A[i][j];
            } 
            else {
                if (A[i][j] == 1) {
                    dp[i][j] = 0;
                } 
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
    }

    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            total+=dp[i][j];
        }
    }
    return total;
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cout << countSquares(A) << endl;
    return 0;
}
