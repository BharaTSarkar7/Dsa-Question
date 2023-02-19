#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

struct Node *linker, *last;

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

int palindrome()
{
    last = first;
    linker = NULL;
    struct Node *prev = NULL;
    while (last != NULL)
    {
        prev = linker;
        linker = last;
        last = last->next;
        linker->next = prev;
    }
    last = linker;
    display(last);
    int flag = 0;
    while (linker)
    {
        printf("%d and %d", first->data, linker->data);
        if (linker->data != first->data)
        {
            flag = 0;
            break;
        }
        linker = linker->next;
        first = first->next;
    }
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    first = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter the number of Node\n");
    scanf("%d", &n);
    create(n);
    if (palindrome())
    {
        printf("palindrome\n");
    }
    else
    {
        printf("Not palindrome\n");
    }

    return 0;
}