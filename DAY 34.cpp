#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int evaluate(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char token[20];

    while (scanf("%s", token) != EOF) {

        if (isdigit(token[0])) {  
            push(atoi(token));
        }
        else {  
            int b = pop();
            int a = pop();
            int result = evaluate(a, b, token[0]);
            push(result);
        }
    }

    printf("%d\n", pop());

    return 0;
}
