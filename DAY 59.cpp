#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

Node* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;
    
    Node* root = createNode(postorder[(*postIndex)--]);
    
    if (inStart == inEnd) return root;
    
    int inIndex = findIndex(inorder, inStart, inEnd, root->val);
    
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, inIndex - 1, postIndex);
    
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int inorder[n], postorder[n];
    
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    
    int postIndex = n - 1;
    Node* root = build(inorder, postorder, 0, n - 1, &postIndex);
    
    preorder(root);
    
    return 0;
}
