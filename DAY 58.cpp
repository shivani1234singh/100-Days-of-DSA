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

Node* build(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;
    
    Node* root = createNode(preorder[(*preIndex)++]);
    
    if (inStart == inEnd) return root;
    
    int inIndex = findIndex(inorder, inStart, inEnd, root->val);
    
    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);
    
    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int preorder[n], inorder[n];
    
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    
    int preIndex = 0;
    Node* root = build(preorder, inorder, 0, n - 1, &preIndex);
    
    postorder(root);
    
    return 0;
}
