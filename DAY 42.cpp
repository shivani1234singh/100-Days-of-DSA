#include <stdio.h>
#include <stdlib.h>

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
    if (!q->rear) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (!q->front) return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return val;
}

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int n) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (int*)malloc(n * sizeof(int));
    s->top = -1;
    s->capacity = n;
    return s;
}

void push(Stack* s, int val) {
    if (s->top < s->capacity - 1)
        s->arr[++s->top] = val;
}

int pop(Stack* s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

int main() {
    int N;
    scanf("%d", &N);
    Queue* q = createQueue();
    Stack* s = createStack(N);
    int val;
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    while (q->front) {
        push(s, dequeue(q));
    }

    while (s->top != -1) {
        printf("%d ", pop(s));
    }
    printf("\n");
    return 0;
}
