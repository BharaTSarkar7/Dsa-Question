#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * third;

struct Node *linker, *last;

void create(struct Node *list, const int limit)
{
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

void Merge(struct Node *p, struct Node *q)
{
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    if (q != NULL)
    {
        last->next = q;
    }
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
    int n;
    printf("Enter the number of Node\n");
    scanf("%d", &n);
    create(first, n);
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number of Node\n");
    fflush(stdin);
    scanf("%d", &n);
    create(second, n);
    Merge(first, second);
    display(third);
    return 0;
}