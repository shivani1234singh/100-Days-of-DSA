#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP 100

typedef struct {
    int arr[MAX_HEAP];
    int size;
} MinHeap;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *heap, int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap->arr[parent] > heap->arr[index]){
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(MinHeap *heap, int index){
    int left, right, smallest;
    while(1){
        left = 2*index + 1;
        right = 2*index + 2;
        smallest = index;
        if(left < heap->size && heap->arr[left] < heap->arr[smallest])
            smallest = left;
        if(right < heap->size && heap->arr[right] < heap->arr[smallest])
            smallest = right;
        if(smallest != index){
            swap(&heap->arr[index], &heap->arr[smallest]);
            index = smallest;
        } else break;
    }
}

void insert(MinHeap *heap, int val){
    if(heap->size >= MAX_HEAP) return;
    heap->arr[heap->size] = val;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int peek(MinHeap *heap){
    if(heap->size == 0) return -1;
    return heap->arr[0];
}

int extractMin(MinHeap *heap){
    if(heap->size == 0) return -1;
    int minVal = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size-1];
    heap->size--;
    heapifyDown(heap, 0);
    return minVal;
}

int main(){
    int N;
    scanf("%d\n", &N);
    MinHeap heap;
    heap.size = 0;
    char op[20];
    int val;
    for(int i = 0; i < N; i++){
        fgets(op, sizeof(op), stdin);
        if(sscanf(op, "insert %d", &val) == 1){
            insert(&heap, val);
        } else if(strncmp(op, "peek", 4) == 0){
            printf("%d\n", peek(&heap));
        } else if(strncmp(op, "extractMin", 10) == 0){
            printf("%d\n", extractMin(&heap));
        }
    }
    return 0;
}
