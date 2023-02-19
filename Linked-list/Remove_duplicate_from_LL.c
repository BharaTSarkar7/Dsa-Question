#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

struct Node *last, *temp;

void create(int limit)
{
    int new_data, i;

    if (first == NULL)
    {
        printf("Memory Not Allocated\n");
    }
    else
    {
        scanf("%d", &new_data);
        first->data = new_data;
        first->next = NULL; // link the address part to NULL because we don't use first pointer anymore to create
        last = first;       // storing next node to temp
    }

    for (i = 1; i < limit; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        if (last == NULL)
        {
            printf("Memory Not Allocated\n");
        }
        else
        {
            scanf("%d", &new_data);
            temp->data = new_data;
            temp->next = NULL; // link next node to NULL

            last->next = temp; // linking previous node to current node
            last = last->next;
        }
    }
}

void Remove()
{
    temp = first->next;
    struct Node *linker = first;
    while (temp != NULL)
    {
        if (linker->data != temp->data)
        {
            linker = temp;
            temp = temp->next;
        }

        else if (linker->data == temp->data)
        {
            linker->next = temp->next;
            temp = linker->next;
        }
    }
}

void display()
{
    struct Node *temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    first = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter the number of Node\n");
    scanf("%d", &n);
    create(n);
    display();
    printf("After remove duplicate\n");
    Remove();
    display();

    return 0;
}