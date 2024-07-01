#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}
int main(){
    int n=0;
    scanf("%d",&n);
    vector<pair<int,int>> missions(n);
    for(int i=0;i<n;i++){
        int a=0,b=0;
        scanf("%d %d",&a,&b);
        missions[i]={a,b};
    }
    sort(missions.begin(),missions.end(),compare);
    int nums=0,total=missions.size();
    while(total>0){
        vector<pair<int,int>>temp;
        for(int i=0;i<total;i++){
            if(missions[i].first>=missions[0].second){
                temp.push_back(missions[i]);
            }
        }
        missions=temp;
        total=missions.size();
        nums++;
    }
    printf("%d\n",nums);
}