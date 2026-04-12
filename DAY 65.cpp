#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int *visited, int **adj, int *size) {
    visited[v] = 1;
    for (int i = 0; i < size[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u, v, visited, adj, size)) return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = malloc(n * sizeof(int *));
    int *size = calloc(n, sizeof(int));
    int *cap = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        cap[i] = 2;
        adj[i] = malloc(cap[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;

        if (size[u] == cap[u]) {
            cap[u] *= 2;
            adj[u] = realloc(adj[u], cap[u] * sizeof(int));
        }
        if (size[v] == cap[v]) {
            cap[v] *= 2;
            adj[v] = realloc(adj[v], cap[v] * sizeof(int));
        }

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int *visited = calloc(n, sizeof(int));
    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}
