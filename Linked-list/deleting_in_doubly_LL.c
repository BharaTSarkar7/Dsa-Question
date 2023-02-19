#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
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

int Length()
{
    int count = 0;
    linker = first;
    while (linker != NULL)
    {
        count++;
        linker = linker->next;
    }
    return count;
}

void Delete()
{
    int posi;
    printf("Enter the position to delete\n");
    scanf("%d", &posi);
    if (posi == 1)
    {
        linker = first;
        first = linker->next;
        linker->next = NULL;
        first->prev = NULL;
    }
    else
    {
        int i = 1;
        linker = first;
        while (i != posi)
        {
            last = linker;
            linker = linker->next;
            i++;
        }
        last->next = linker->next;
        linker = linker->next;
        linker->prev = last;
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
    Delete();
    display();
    return 0;
}