#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct QNode {
    struct TreeNode* node;
    int hd;
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

        if (arr[i] != -1) {
            cur->left = newNode(arr[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            q[r++] = cur->right;
        }
        i++;
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

    struct QNode* q = (struct QNode*)malloc(n * sizeof(struct QNode));
    int f = 0, r = 0;

    int hd[200], val[200], size = 0;

    q[r++] = (struct QNode){root, 0};

    int min = 0, max = 0;

    while (f < r) {
        struct QNode temp = q[f++];
        struct TreeNode* node = temp.node;
        int h = temp.hd;

        hd[size] = h;
        val[size++] = node->val;

        if (h < min) min = h;
        if (h > max) max = h;

        if (node->left)
            q[r++] = (struct QNode){node->left, h - 1};
        if (node->right)
            q[r++] = (struct QNode){node->right, h + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < size; j++) {
            if (hd[j] == i) printf("%d ", val[j]);
        }
        printf("\n");
    }

    free(arr);
    free(q);
    return 0;
}
