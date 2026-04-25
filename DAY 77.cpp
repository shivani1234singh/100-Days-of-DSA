#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **adj, int *vis) {
    vis[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !vis[i]) {
            dfs(i, n, adj, vis);
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

    int *vis = (int *)calloc(n + 1, sizeof(int));

    dfs(1, n, adj, vis);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}
