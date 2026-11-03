#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};

/* Function to insert a new node at the front of the list */
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to insert a node at a specified position */
void ins_at_pos_n(struct Node** head_ref, int data, int position)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data; // Creating a new node

    int i;
    struct Node *temp = *head_ref;

    if (position == 1)
    {
        ptr->next = temp;
        *head_ref = ptr;
        return;
    }

    // moving to the (position - 1)th node in the linked list
    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nCannot insert at position %d (Out of bounds)\n", position);
        free(ptr);
        return;
    }

    ptr->next = temp->next; // Make newly created node point to next node
    temp->next = ptr;       // Make temp point to newly created node
}

/* Function to append a new node at the end of the list */
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; /* used in step 5 */

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of it as NULL */
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

/* Function to print contents of linked list starting from head */
void printList(struct Node *node)
{
    if (node == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Driver program */
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    printf("--- Singly Linked List: Insertion Operations ---\n");

    // Insert at the end
    append(&head, 6);
    printf("After appending 6: ");
    printList(head);

    // Insert at the beginning
    push(&head, 7);
    printf("After pushing 7 at beginning: ");
    printList(head);

    push(&head, 1);
    printf("After pushing 1 at beginning: ");
    printList(head);

    // Insert at end
    append(&head, 4);
    printf("After appending 4 at end: ");
    printList(head);

    // Insert at specified position
    ins_at_pos_n(&head, 15, 3);
    printf("After inserting 15 at position 3: ");
    printList(head);

    return 0;
}
