#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

struct Node *linker, *last;

void create(const int limit)
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

int isLOOP()
{
    linker = first;
    last = first;
    do
    {
        linker = linker->next;
        last = last->next;
        last = last ? last->next : last;

    } while (linker && last && last != linker);
    if (last == linker)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    linker = first;
    while (linker != NULL)
    {
        printf("%d ", linker->data);
        linker = linker->next;
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
    struct Node *t1, *t2;
    t1 = first;
    t2 = first->next->next->next->next;
    t2->next = t1;

    if (isLOOP())
    {
        printf("Linked list is in loop\n");
    }
    else
    {
        printf("Linked list not in a loop\n");
    }

    return 0;
}