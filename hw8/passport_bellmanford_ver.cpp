#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

struct edge
{
    int u, v, w;
};

long bellman_ford(int n, int m, int s, int t, int level_max, vector<edge> level[])
{
    vector<long> dist(n + 1, LONG_MAX);
    dist[s] = 0;
    long ans = LONG_MAX;
    for (int i = 0; i <= level_max; i++)
    {   
        bool updated = false;
        for (int ii = 0; ii < n - 1; ii++)
        {
            for (int j = 0; j < level[i].size(); j++)
            {
                int u = level[i][j].u, v = level[i][j].v, w = level[i][j].w;
                if (dist[u] != LONG_MAX && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
        }
        if (ans > dist[t] + i * 100)
        {
            ans = dist[t] + i * 100;
        }
        if (!updated)
        {
            break;
        }
    }
    return ans;
}

int main()
{

    int n, m, s, t;
    int level_max = 0;
    cin >> n >> m >> s >> t;
    vector<edge> level[21];
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edge e;
        edge e2;
        e.u = a;
        e.v = b;
        e.w = c;
        e2.u=b;
        e2.v=a;
        e2.w=c;
        level_max = max(d, level_max);
        level[d].push_back(e);
        level[d].push_back(e2);
    }

    cout << bellman_ford(n, m, s, t, level_max, level);
    return 0;
}