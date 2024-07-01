#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int n, m, s, t;

struct node
{
    int value = 0;
    int distance = 0;
    struct node *next = NULL;
    int level = 0;
    int weight = 0;
    bool operator<(const node e) const
    {
        return distance > e.distance;
    }
};

long min_value(vector<struct node> edges, int max_level)
{
    int level_now = 0;
    long ans = LONG_MAX;

    edges[s].distance = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != s)
        {
            edges[i].distance = INT_MAX;
        }
    }
    while (level_now <= max_level)
    {
        int visited[n] = {0};
        for (int j = 0; j < n; j++)
        {
            priority_queue<node> q;
            for (int i = 0; i < n; i++)
            {
                if (visited[i] == 0)
                {
                    q.push(edges[i]);
                }
            }

            int i = q.top().value - 1;

            auto temp = edges[i].next;
            while (temp != NULL)
            {
                if (temp->level <= level_now && temp->level > level_now - 1)
                {
                    if (edges[temp->value - 1].distance > edges[i].distance + temp->weight)
                    {
                        edges[temp->value - 1].distance = edges[i].distance + temp->weight;
                    }
                }
                temp = temp->next;
            }

            visited[i] = 1;
        }
        if (ans > edges[t].distance + level_now * 100)
        {
            ans = edges[t].distance + level_now * 100;
        }
        level_now++;
    }
    return ans;
}

int main()
{

    cin >> n >> m >> s >> t;
    if (s == t)
    {
        cout << '0' << endl;
        return 0;
    }
    s--;
    t--;
    vector<struct node> edges(n);
    for (int i = 0; i < n; i++)
    {
        edges[i].value = i + 1;
    }
    int max_level = 0;
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0, c = 0, d = 0;
        cin >> a >> b >> c >> d;
        if (d > max_level)
        {
            max_level = d;
        }
        auto temp = new struct node;
        temp->value = b;
        temp->weight = c;
        temp->level = d;
        temp->next = edges[a - 1].next;

        edges[a - 1].next = temp;
    }

    cout << min_value(edges, max_level) << endl;
    return 0;
}