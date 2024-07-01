#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    if(abs(a)<1e9&&abs(b)<1e9){
        cout<<a+b<<endl;
    }
    else{
        cout<<"error"<<endl;
    }
    return 0;
}