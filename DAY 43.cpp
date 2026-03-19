#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Queue {
    TreeNode** arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (TreeNode**)malloc(capacity * sizeof(TreeNode*));
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, TreeNode* node) {
    if(q->size == q->capacity) return;
    q->arr[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

TreeNode* dequeue(Queue* q) {
    if(q->size == 0) return NULL;
    TreeNode* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

TreeNode* createNode(int val) {
    if(val == -1) return NULL;
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if(N == 0) return 0;

    TreeNode* root = createNode(arr[0]);
    Queue* q = createQueue(N);
    enqueue(q, root);
    int i = 1;

    while(i < N) {
        TreeNode* curr = dequeue(q);
        if(!curr) continue;

        if(i < N) {
            curr->left = createNode(arr[i++]);
            if(curr->left) enqueue(q, curr->left);
        }

        if(i < N) {
            curr->right = createNode(arr[i++]);
            if(curr->right) enqueue(q, curr->right);
        }
    }

    inorder(root);
    printf("\n");
    return 0;
}
