#include<iostream>
#include<vector>
using namespace std;

//find and cout
void find_longest_common_subsequence(vector<int> A,vector<int> B){
    //use dynamic programming and recursive method
    int m=A.size();
    int n=B.size();
    vector<vector<int>> c(2,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1]){
                c[1][j]=c[0][j-1]+1;
            }
            else{
                c[1][j]=max(c[0][j],c[1][j-1]);
            }
        }
        
        c[0]=c[1];
        
    }
    cout<< c[0][n];
}
int main(){
    int n=0;
    cin>>n;
    vector<int> A(n),B(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    find_longest_common_subsequence(A,B);
    return 0;
}