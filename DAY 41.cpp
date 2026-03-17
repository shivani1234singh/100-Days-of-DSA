#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d\n", &N);
    Queue* q = createQueue();
    char op[20];
    int val;
    for (int i = 0; i < N; i++) {
        fgets(op, sizeof(op), stdin);
        if (sscanf(op, "enqueue %d", &val) == 1) {
            enqueue(q, val);
        } else if (strncmp(op, "dequeue", 7) == 0) {
            printf("%d\n", dequeue(q));
        }
    }
    return 0;
}
