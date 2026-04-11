#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->next = NULL;
    return n;
}

void dfs(int v, Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    
    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->val]) {
            dfs(temp->val, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
    
    int s;
    scanf("%d", &s);
    
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    
    dfs(s, adj, visited);
    
    return 0;
}
