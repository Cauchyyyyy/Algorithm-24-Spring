//Minimum Spanning tree in weighted graph
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
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

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int ans = 0;
    for (const auto &e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            ans += e.w;
            union_set(e.u, e.v, parent);
        }
    }

    cout << ans << endl;
    return 0;
}
