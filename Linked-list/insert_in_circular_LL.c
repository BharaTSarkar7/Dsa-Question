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
    last->next = first;
}

int Length()
{
    int count = 0;
    linker = first;
    do
    {
        count++;
        linker = linker->next;
    } while (linker != first);
    return count;
}

void insert()
{
    int i = 1;
    struct Node *nodeToinsert = (struct Node *)malloc(sizeof(struct Node));
    int posi, new_data;
    printf("Enter the Position to insert\n");
    scanf("%d", &posi);
    printf("Enter the data to insert\n");
    scanf("%d", &new_data);
    nodeToinsert->data = new_data;
    if (posi == Length())
    {
        last->next = nodeToinsert;
        nodeToinsert->next = first;
    }
    else if (posi == 1)
    {
        last->next = nodeToinsert;
        nodeToinsert->next = first;
        first = nodeToinsert;
    }
    else
    {
        linker = first;
        while (i != posi - 1)
        {
            linker = linker->next;
        }
        nodeToinsert->next = linker->next;
        linker->next = nodeToinsert;
    }
}

void display()
{
    linker = first;
    do
    {
        printf("%d ", linker->data);
        linker = linker->next;
    } while (linker != first);
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