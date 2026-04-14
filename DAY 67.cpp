#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

int stack[MAX];
int top = -1;
int visited[MAX];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void initGraph(struct Graph* graph, int V) {
    graph->V = V;
    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
        visited[i] = 0;
    }
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void push(int v) {
    stack[++top] = v;
}

void dfs(struct Graph* graph, int v) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(graph, temp->vertex);
        }
        temp = temp->next;
    }

    push(v);
}

void topologicalSort(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfs(graph, i);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    initGraph(&graph, 6);

    addEdge(&graph, 5, 2);
    addEdge(&graph, 5, 0);
    addEdge(&graph, 4, 0);
    addEdge(&graph, 4, 1);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 1);

    topologicalSort(&graph);

    return 0;
}
