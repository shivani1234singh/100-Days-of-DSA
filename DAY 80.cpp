#include <stdio.h>

#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int dist[105][105];

    // Input adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);

            if (i == j) {
                dist[i][j] = 0;
            } else if (x == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = x;
            }
        }
    }

    // Floyd-Warshall core
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }

            }
        }
    }

    // Output result
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);

        }
        printf("\n");
    }

    return 0;
}
