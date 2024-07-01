#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    if(n<1||n>1e6||x<0||x>9){
        cout<<"error"<<endl;
        return 0;
    }
    int t=0;
    for(int i=1;i<=n;i++){
        int e=i%10,
            d=((i-e)%100)/10,
            c=((i-e-10*d)%1000)/100,
            b=((i-e-d*10-c*100)%10000)/1000,
            a=((i-e-d*10-c*100-b*1000)%100000)/10000,
            f=(i-e-d*10-c*100-b*1000-a*1e4)/100000;
        int arr[]={a,b,c,d,e,f};
        for(int j=0;j<6;j++){
            if(arr[j]==x){
                t++;
            }
        }
    }
    cout<<t;
    return 0;
}