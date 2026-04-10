#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    int *size = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        size[i] = k;
        adj[i] = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    int *visited = (int *)calloc(n, sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < size[v]; i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = 1;
                queue[rear++] = u;
            }
        }
    }

    return 0;
}
