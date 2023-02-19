#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * first;

struct Node *last, *temp;

void create(int limit)
{
    int new_data, i;
    if (first == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    else
    {
        scanf("%d", &new_data);
        first->data = new_data;
        first->next = NULL;
        last = first;
        for (i = 1; i < limit; i++)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            if (temp == NULL)
            {
                printf("Error\n");
                exit(0);
            }
            scanf("%d", &new_data);
            temp->data = new_data;
            temp->next = NULL;

            last->next = temp;
            last = last->next;
        }
    }
}

void insert(const int insert_data)
{
    temp = first;
    struct Node *nodeToinsert = (struct Node *)malloc(sizeof(struct Node));
    struct Node *linker = NULL;
    while (temp && temp->data < insert_data)
    {
        linker = temp;
        temp = temp->next;
    }
    nodeToinsert->data = insert_data;
    nodeToinsert->next = temp;
    linker->next = nodeToinsert;
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
    insert(6);
    display();
    return 0;
}