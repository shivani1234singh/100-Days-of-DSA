#include <stdio.h>
#include <limits.h>

#define MAX 1005

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // initialize adjacency matrix with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // read edges (undirected graph)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (w < graph[u][v]) { // handle multiple edges
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int key[MAX];
    int mstSet[MAX];
    int parent[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    key[1] = 0; // start from node 1

    for (int count = 1; count <= n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;

    for (int i = 2; i <= n; i++) {
        if (parent[i] != -1) {
            totalWeight += graph[i][parent[i]];
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
