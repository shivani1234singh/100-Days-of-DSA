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
    
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adj[i];
        while (temp) {
            printf(" %d", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
    
    return 0;
}
