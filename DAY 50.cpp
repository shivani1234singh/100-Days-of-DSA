#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root) {
        if (root->val == val) return root;
        if (val < root->val) root = root->left;
        else root = root->right;
    }
    return NULL;
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    int val = 2;
    struct TreeNode* result = searchBST(root, val);

    if (result) printf("Found: %d\n", result->val);
    else printf("Not Found\n");

    return 0;
}
