#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topo[MAX];

    while (front < rear) {
        int u = queue[front++];
        topo[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != n) {
        printf("Cycle detected\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}
