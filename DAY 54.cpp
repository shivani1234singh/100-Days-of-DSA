#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode** q = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int f = 0, r = 0;
    struct TreeNode* root = newNode(arr[0]);
    q[r++] = root;
    int i = 1;
    while (i < n) {
        struct TreeNode* cur = q[f++];
        if (arr[i] != -1) { cur->left = newNode(arr[i]); q[r++] = cur->left; } i++;
        if (i < n && arr[i] != -1) { cur->right = newNode(arr[i]); q[r++] = cur->right; } i++;
    }
    free(q);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct TreeNode* root = buildTree(arr, n);
    free(arr);

    struct TreeNode** q = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int f = 0, r = 0;
    if(root) q[r++] = root;
    int level = 0;
    while(f < r) {
        int sz = r - f;
        struct TreeNode** temp = (struct TreeNode**)malloc(sz * sizeof(struct TreeNode*));
        for(int i = 0; i < sz; i++) temp[i] = q[f+i];
        if(level % 2 == 0) {
            for(int i = 0; i < sz; i++) printf("%d ", temp[i]->val);
        } else {
            for(int i = sz-1; i >=0; i--) printf("%d ", temp[i]->val);
        }
        for(int i = 0; i < sz; i++) {
            if(temp[i]->left) q[r++] = temp[i]->left;
            if(temp[i]->right) q[r++] = temp[i]->right;
        }
        f += sz;
        level++;
        free(temp);
    }
    free(q);
    return 0;
}
