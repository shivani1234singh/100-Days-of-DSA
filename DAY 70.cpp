#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source;
    scanf("%d", &source);

    int *dist = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}
