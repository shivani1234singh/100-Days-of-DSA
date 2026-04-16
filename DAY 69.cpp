#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

typedef struct {
    Edge** head;
    int n;
} Graph;

typedef struct Node {
    int v, dist;
} Node;

typedef struct {
    Node* arr;
    int size, cap;
} PQ;

Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->head = (Edge**)calloc(n, sizeof(Edge*));
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    e->next = g->head[u];
    g->head[u] = e;
}

PQ* createPQ(int cap) {
    PQ* pq = (PQ*)malloc(sizeof(PQ));
    pq->arr = (Node*)malloc(cap * sizeof(Node));
    pq->size = 0;
    pq->cap = cap;
    return pq;
}

void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(PQ* pq, int v, int dist) {
    int i = pq->size++;
    pq->arr[i].v = v;
    pq->arr[i].dist = dist;
    while (i && pq->arr[(i - 1) / 2].dist > pq->arr[i].dist) {
        swap(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(PQ* pq) {
    Node root = pq->arr[0];
    pq->arr[0] = pq->arr[--pq->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < pq->size && pq->arr[l].dist < pq->arr[smallest].dist)
            smallest = l;
        if (r < pq->size && pq->arr[r].dist < pq->arr[smallest].dist)
            smallest = r;
        if (smallest == i) break;
        swap(&pq->arr[i], &pq->arr[smallest]);
        i = smallest;
    }
    return root;
}

int isEmpty(PQ* pq) {
    return pq->size == 0;
}

void dijkstra(Graph* g, int src) {
    int* dist = (int*)malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    PQ* pq = createPQ(g->n * 10);
    push(pq, src, 0);

    while (!isEmpty(pq)) {
        Node cur = pop(pq);
        int u = cur.v;

        if (cur.dist > dist[u]) continue;

        Edge* e = g->head[u];
        while (e) {
            int v = e->v;
            int w = e->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, v, dist[v]);
            }
            e = e->next;
        }
    }

    for (int i = 0; i < g->n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    Graph* g = createGraph(n);

    addEdge(g, 0, 1, 10);
    addEdge(g, 0, 4, 5);
    addEdge(g, 1, 2, 1);
    addEdge(g, 4, 1, 3);
    addEdge(g, 4, 2, 9);
    addEdge(g, 4, 3, 2);
    addEdge(g, 3, 2, 4);
    addEdge(g, 2, 3, 6);

    dijkstra(g, 0);
    return 0;
}
