#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int count;
} Deque;

void init(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

int empty(Deque *dq) {
    return dq->count == 0;
}

int size(Deque *dq) {
    return dq->count;
}

void push_back(Deque *dq, int x) {
    if (dq->count == MAX) return;
    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = x;
    dq->count++;
}

void push_front(Deque *dq, int x) {
    if (dq->count == MAX) return;
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = x;
    dq->count++;
}

int pop_front(Deque *dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX;
    dq->count--;
    return val;
}

int pop_back(Deque *dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->count--;
    return val;
}

int front(Deque *dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque *dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void clear(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

void reverse(Deque *dq) {
    if (dq->count <= 1) return;
    int i = dq->front, j = dq->rear;
    for (int k = 0; k < dq->count / 2; k++) {
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;
        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

void printDeque(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    for (int c = 0; c < dq->count; c++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    init(&dq);
    
    push_back(&dq, 10);
    push_front(&dq, 5);
    push_back(&dq, 20);
    printDeque(&dq);
    
    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    
    pop_front(&dq);
    pop_back(&dq);
    printDeque(&dq);
    
    push_back(&dq, 30);
    push_back(&dq, 25);
    reverse(&dq);
    printDeque(&dq);
    
    clear(&dq);
    printDeque(&dq);
    
    return 0;
}
