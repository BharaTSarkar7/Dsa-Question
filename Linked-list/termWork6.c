#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct node **head, int data)
{
    struct node *newNode = createNode(data);

    if (*head == NULL)
    {
        (*head) = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL && current->data < data)
    {
        current = current->next;
    }

    if (current->data >= data)
    {
        if (current->prev == NULL)
        {
            newNode->next = current;
            current->prev = newNode;
            (*head) = newNode;
        }
        else
        {
            current->prev->next = newNode;
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev = newNode;
        }
    }
    else
    {
        current->next = newNode;
        newNode->prev = current;
    }
}

void display(struct node *head)
{
    struct node *cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n;
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d", &n);
    while (n)
    {
        int choice;
        printf("\nEnter 1 to insert\nEnter 2 to display list\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int new_data;
            printf("\nEnter the data\n");
            scanf("%d", &new_data);
            insertNode(&head, new_data);
            break;

        case 2:
            display(head);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }
    return 0;
}