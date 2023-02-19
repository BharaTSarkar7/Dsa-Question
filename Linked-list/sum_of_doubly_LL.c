#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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

int Sum()
{
    int tot = 0;
    last = first;
    while (last != NULL)
    {
        tot += last->data;
        last = last->next;
    }
    return tot;
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
    printf("Sum of all elements is %d", Sum());
    return 0;
}