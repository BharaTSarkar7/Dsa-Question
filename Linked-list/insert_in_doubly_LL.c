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

void insert()
{
    struct Node *nodeToinsert = (struct Node *)malloc(sizeof(struct Node));
    nodeToinsert->next = NULL;
    nodeToinsert->prev = NULL;
    int posi, new_data;
    printf("Enter the position you want to insert\n");
    scanf("%d", &posi);
    printf("Enter the data to insert\n");
    scanf("%d", &new_data);
    if (posi == 1)
    {
        last = first;
        nodeToinsert->data = new_data;
        nodeToinsert->next = last;
        nodeToinsert->prev = NULL;
        first = nodeToinsert;
    }
    else if (posi > Length() && posi < Length() + 2)
    {
        nodeToinsert->data = new_data;
        nodeToinsert->next = NULL;
        nodeToinsert->prev = last;
        last->next = nodeToinsert;
        last = nodeToinsert;
    }
    else
    {
        nodeToinsert->data = new_data;
        last = first;
        int i = 1;
        while (i != posi - 1)
        {
            last = last->next;
            i++;
        }
        nodeToinsert->next = last->next;
        nodeToinsert->prev = last;
        last->next = nodeToinsert;
        last = nodeToinsert->next;
        last->prev = nodeToinsert;
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
    insert();
    display();
    return 0;
}