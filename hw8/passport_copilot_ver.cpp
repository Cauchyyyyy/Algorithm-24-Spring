#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define MAXM 10005
#define INF 0x3f3f3f3f

typedef struct {
    int v, w, a;
} Edge;

typedef struct {
    int u, cost, level;
} Node;

Edge edges[MAXM];
Node heap[MAXM];
int head[MAXN], next[MAXM], dist[MAXN][MAXN], vis[MAXN][MAXN];
int n, m, s, t, cnt, size;

void addEdge(int u, int v, int w, int a) {
    edges[cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].a = a;
    next[cnt] = head[u];
    head[u] = cnt++;
}

void push(Node node) {
    int i, j;
    for (i = ++size; i > 1 && node.cost < heap[j = i / 2].cost; i = j)
        heap[i] = heap[j];
    heap[i] = node;
}

Node pop() {
    int i, j;
    Node node = heap[1], temp = heap[size--];
    for (i = 1; i * 2 <= size; i = j) {
        j = i * 2;
        if (j < size && heap[j+1].cost < heap[j].cost)
            j++;
        if (heap[j].cost >= temp.cost)
            break;
        heap[i] = heap[j];
    }
    heap[i] = temp;
    return node;
}

int dijkstra() {
    int i, u, v, w, a, cost, level;
    Node node;
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s][0] = 0;
    push((Node){s, 0, 0});
    while (size) {
        node = pop();
        u = node.u;
        level = node.level;
        if (vis[u][level])
            continue;
        vis[u][level] = 1;
        for (i = head[u]; ~i; i = next[i]) {
            v = edges[i].v;
            w = edges[i].w;
            a = edges[i].a;
            cost = dist[u][level] + w + (a > level ? (a - level) * 100 : 0);
            if (cost < dist[v][a]) {
                dist[v][a] = cost;
                push((Node){v, cost, a});
            }
        }
    }
    cost = INF;
    for (i = 0; i <= n; i++)
        if (dist[t][i] < cost)
            cost = dist[t][i];
    return cost;
}

int main() {
    int i, u, v, w, a;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(head, -1, sizeof(head));
    cnt = size = 0;
    for (i = 0; i < m; i++) {
        scanf("%d%d%d%d", &u, &v, &w, &a);
        addEdge(u, v, w, a);
        addEdge(v, u, w, a);
    }
    printf("%d\n", dijkstra());
    return 0;
}