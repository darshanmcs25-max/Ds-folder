#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Prototypes from PPT */
void beginsert(int item);
void begin_delete();
void last_delete();
void random_delete();
void display();

/* Function to insert at beginning to populate the list */
void beginsert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    printf("\nNode inserted: %d", item);
}

/* Delete a node at the front */
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning ...\n");
    }
}

/* Delete a node at the end */
void last_delete()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nonly node of the list deleted ...\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}

/* Delete node after/at specified location */
void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\nEnter the location of the node after which you want to perform deletion: ");
    scanf("%d", &loc);

    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nCan't delete\n");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d\n", loc + 1);
}

/* Display the contents of the linked list */
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nNothing to print\n");
    }
    else
    {
        printf("\nprinting values ...\n");
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

/* Driver program with Menu */
int main()
{
    int choice = 0;
    int item;

    while (choice != 6)
    {
        printf("\n\n********* Singly Linked List Deletion Menu *********\n");
        printf("1. Insert node at beginning\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from Last\n");
        printf("4. Delete node after specified location\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                beginsert(item);
                break;
            case 2:
                begin_delete();
                break;
            case 3:
                last_delete();
                break;
            case 4:
                random_delete();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nPlease enter a valid choice.\n");
        }
    }
    return 0;
}
