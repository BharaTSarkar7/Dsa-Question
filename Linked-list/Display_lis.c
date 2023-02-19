#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void create(struct Node *first, int d)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->next = first;
    first = temp;
}

void display(struct Node *first)
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
    struct Node *new_node = NULL;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = new_node;
    create(first, 10);
    display(first);
    create(first, 12);
    display(first);
    return 0;
}