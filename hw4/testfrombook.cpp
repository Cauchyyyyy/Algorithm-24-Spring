#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
int main(){
    double p[]={0,0.04,0.06,0.08,0.02,0.10,0.12,0.14};
    double q[]={0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05};
    double e[8][8]={0},w[8][8]={0},root[7][7]={0};
    for(int i=0;i<8;i++){
        e[i][i]=w[i][i]=q[i];
    }
    for(int l=1;l<8;l++){
        for(int i=1;i<=8-l;i++){
            int j=i+l-1;
            w[i-1][j]=w[i-1][j-1]+p[j]+q[j];
            e[i-1][j]=w[i-1][j]+e[i-1][i-1]+e[i][j];
            for(int k=i;k<=j;k++){
                e[i-1][j]=min(e[i-1][j],e[i-1][k-1]+e[k][j]+w[i-1][j]);
            }
        }
    }
    //print e
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<e[i][j]<<"\t";
        }
        cout<<endl;
    }
    //print w
    cout<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<w[i][j]<<"\t";
        }
        cout<<endl;
    }
}