#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// create function

void create(struct Node *list, const int limit)
{
    struct Node *linker = NULL, *last = NULL;
    int i, new_data;
    scanf("%d", &new_data);
    list->data = new_data;
    list->next = NULL;
    last = list;
    for (i = 1; i < limit; i++)
    {
        linker = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &new_data);
        linker->data = new_data;
        linker->next = NULL;

        last->next = linker;
        last = last->next;
    }
}

struct Node *deleteNode(struct Node *head, int posi)
{
    if (posi < 1)
        return head; // if posi is less then 1 return head becoz opertion cant be done
    if (head == NULL)
        return NULL; // if head is NULL return  NULL
    if (posi == 1)
    {
        struct Node *linker = head;
        head = head->next; // shift head to head next
        free(linker);      // delete the first node
        return head;
    }

    head->next = deleteNode(head->next, posi - 1);
    return head;
}

// display function

void display(struct Node *list)
{
    struct Node *temp = list;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter the number of Node\n");
    scanf("%d", &n);
    create(first, n);
    printf("Enter the position to delete\n");
    int posi;
    scanf("%d", &posi);
    first = deleteNode(first, posi);
    display(first);
    return 0;
}