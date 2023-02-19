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

struct Node *removeElements(int val)
{
    struct Node *head = first;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (head && head->data == val)
    {
        head = head->next;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
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
    first = removeElements(7);
    display();
    return 0;
}