#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void Push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void Pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

void DisplayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void Enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

void Dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = *front;
    printf("%d\n", temp->data);
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void DisplayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    Push(&top, 10);
    Push(&top, 20);
    Push(&top, 30);
    DisplayStack(top);
    Pop(&top);
    DisplayStack(top);

    struct Node* front = NULL;
    struct Node* rear = NULL;
    Enqueue(&front, &rear, 100);
    Enqueue(&front, &rear, 200);
    Enqueue(&front, &rear, 300);
    DisplayQueue(front);
    Dequeue(&front, &rear);
    DisplayQueue(front);

    return 0;
}

