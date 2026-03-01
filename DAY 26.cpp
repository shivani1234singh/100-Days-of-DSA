#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, struct Node** tail, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(&head, &tail, val);
    }

    printList(head);

    return 0;
}
