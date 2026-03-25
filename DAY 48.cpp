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

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) {
        printf("0");
        return 0;
    }

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

    printf("%d", countLeaves(nodes[0]));
    return 0;
}
