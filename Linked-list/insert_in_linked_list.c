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

int Length()
{
    int count = 0;
    temp = first;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert(int poistion, const int insert_data)
{
    int index = 1;
    struct Node *nodeToinsert = (struct Node *)malloc(sizeof(struct Node));
    if (poistion == 1)
    {
        nodeToinsert->data = insert_data;
        nodeToinsert->next = first;
        first = nodeToinsert;
    }
    else if (poistion == Length())
    {
        nodeToinsert->data = insert_data;
        nodeToinsert->next = NULL;
        last->next = nodeToinsert;
        last = nodeToinsert;
    }
    else
    {
        temp = first;

        nodeToinsert->data = insert_data;
        while (index < poistion - 1)
        {
            temp = temp->next;
            index++;
        }
        nodeToinsert->next = temp->next;
        temp->next = nodeToinsert;
    }
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
    insert(5, 7);
    printf("After insert\n");
    display();
    return 0;
}