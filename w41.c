#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void InsertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void DisplayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void SortList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* lptr = NULL;
    int swapped;
    struct Node* ptr1;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped == 1);
}

void ReverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

struct Node* ConcatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void FreeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    InsertEnd(&list1, 40);
    InsertEnd(&list1, 10);
    InsertEnd(&list1, 30);
    InsertEnd(&list1, 20);

    InsertEnd(&list2, 50);
    InsertEnd(&list2, 60);

    printf("Original List 1: ");
    DisplayList(list1);

    SortList(list1);
    printf("Sorted List 1: ");
    DisplayList(list1);

    ReverseList(&list1);
    printf("Reversed List 1: ");
    DisplayList(list1);

    printf("List 2: ");
    DisplayList(list2);

    list1 = ConcatenateLists(list1, list2);
    printf("Concatenated List: ");
    DisplayList(list1);

    // Free all allocated nodes (list2 is now attached to list1)
    FreeList(list1);

    return 0;
}

