#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **adj, int *visited) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int *)calloc(n + 1, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int *visited = (int *)calloc(n + 1, sizeof(int));
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj, visited);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
