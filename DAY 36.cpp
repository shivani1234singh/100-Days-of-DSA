#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int count = 0;

void enqueue(int x, int size) {
    if (count == size) return; // queue full

    rear = (rear + 1) % size;
    queue[rear] = x;
    count++;
}

void dequeue(int size) {
    if (count == 0) return; // queue empty

    front = (front + 1) % size;
    count--;
}

void display(int size) {
    int i, idx = front;

    for (i = 0; i < count; i++) {
        printf("%d ", queue[idx]);
        idx = (idx + 1) % size;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(n);
    }

    display(n);

    return 0;
}
