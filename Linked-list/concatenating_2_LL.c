#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *linker, *last;

void create(struct Node *first, const int limit)
{
    int i, new_data;
    scanf("%d", &new_data);
    first->data = new_data;
    first->next = NULL;
    last = first;
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

void concatenate(struct Node *distination, struct Node *target)
{
    last = distination;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = target;
    target = NULL;
}

void display(struct Node *list)
{
    linker = list;
    while (linker != NULL)
    {
        printf("%d ", linker->data);
        linker = linker->next;
    }
    printf("\n");
}

int main()
{
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter the number of Node for first list\n");
    scanf("%d", &n);
    create(first, n);
    display(first);
    printf("Enter the number of Node for second list\n");
    fflush(stdin);
    scanf("%d", &n);
    create(second, n);
    display(second);
    concatenate(first, second);
    display(first);

    return 0;
}