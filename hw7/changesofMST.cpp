//give a tree, then add edges
//update the minimum spanning tree
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    int time;
    bool used=false;
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

int find(int x, vector<int> &parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void union_set(int x, int y, vector<int> &parent) {
    int root_x = find(x, parent);
    int root_y = find(y, parent);
    if (root_x != root_y) {
        parent[root_x] = root_y;
    }
}

int makeMST(vector<Edge> &edges) {
    int N=edges.size();
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int ans = 0;
    for ( auto &e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            ans += e.w;
            e.used=true;
            union_set(e.u, e.v, parent);
        }
    }

    return ans;
}

int main() {
    int N, M0, M;
    cin >> N >> M0>>M;
    vector<Edge> edges(M+M0);
    
    for (int i = 0; i < M+M0; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].time=i;
    }
    sort(edges.begin(), edges.end());

    int ans[M] = {0};
    int answer=ans[0]=makeMST(edges);
    int M1=M;
    while(M>1){
        M--;
        int this_time=0;
        Edge temp;
        for(int i=0;i<M+M0;i++){
            if(edges[i].time==M+M0){
                temp=edges[i];
                for(int j=i;j<M+M0-1;j++){
                    edges[j]=edges[j+1];
                    
                }
                break;
            }
            
        }
        edges.pop_back();
        if(temp.used==false){
            ans[M]=answer;
        }
        else{
            for( auto &e : edges) {
                e.used=false;
            }
            ans[M]=answer=makeMST(edges);
        }
        
    }

    for(int i=1;i<M1;i++){
        cout<<ans[i]<<endl;
    }
    cout<<ans[0]<<endl;
    return 0;
}
