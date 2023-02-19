#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

} * first;

struct Node *last, *linker;

void create(const int limit)
{
    int i, new_data;
    scanf("%d", &new_data);
    first->data = new_data;
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for (i = 1; i < limit; i++)
    {
        linker = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &new_data);
        linker->data = new_data;
        linker->next = NULL;
        linker->prev = last;

        last->next = linker;
        last = last->next;
    }
}

void reverse()
{
    linker = NULL;
    last = first;
    while (last != NULL)
    {
        linker = last->next;
        last->next = last->prev;
        last->prev = linker;
        last = last->prev;
        if (last != NULL && last->next == NULL)
        {
            first = last;
        }
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
    reverse();
    display();

    return 0;
}