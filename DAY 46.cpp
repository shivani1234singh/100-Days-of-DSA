#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) nodes[i] = newNode(arr[i]);
        else nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            int l = 2*i+1, r = 2*i+2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = nodes[0];

    while (front < rear) {
        Node* cur = queue[front++];
        if (!cur) continue;
        printf("%d ", cur->data);
        if (cur->left) queue[rear++] = cur->left;
        if (cur->right) queue[rear++] = cur->right;
    }

    return 0;
}
