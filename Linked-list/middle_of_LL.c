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

int Length()
{
    linker = first;
    int count = 0;
    while (linker != NULL)
    {
        linker = linker->next;
        count++;
    }
    return count;
}

int Middle()
{
    last = first;
    int start = 1, end = Length(), i = 1;
    int mid = start + (end - start) / 2;
    while (i != mid)
    {
        last = last->next;
        i++;
    }
    int ret_data = last->data;
    return ret_data;
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
    int print = Middle();
    printf("Middle element is %d\n", print);
    return 0;
}