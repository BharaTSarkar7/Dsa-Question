#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node **head_ref, struct node **last_ref, int new_data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = new_data;
    newNode->next = NULL;
    if ((*head_ref) == NULL)
    {
        (*last_ref) = (*head_ref) = newNode;
    }
    else
    {
        (*last_ref)->next = newNode;
        (*last_ref) = (*last_ref)->next;
    }
    return (*head_ref);
}

void CreateTwoList(struct node **head_ref, struct node **odd_pos, struct node **even_pos)
{
    int i = 1;
    struct node *odd_temp = NULL;
    struct node *even_temp = NULL;
    while ((*head_ref) != NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (i % 2 != 0)
        {
            temp = (*head_ref);
            (*head_ref) = (*head_ref)->next;
            temp->next = NULL;
            if ((*odd_pos) == NULL)
            {
                (*odd_pos) = odd_temp = temp;
            }
            else
            {
                odd_temp->next = temp;
                odd_temp = odd_temp->next;
            }
        }
        else if (i % 2 == 0)
        {
            temp = (*head_ref);
            (*head_ref) = (*head_ref)->next;
            temp->next = NULL;
            if ((*even_pos) == NULL)
            {
                (*even_pos) = even_temp = temp;
            }
            else
            {
                even_temp->next = temp;
                even_temp = even_temp->next;
            }
        }
        i++;
    }
}

void display(struct node *list)
{
    struct node *temp = list;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *Odd = NULL;
    struct node *even = NULL;
    int n;
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d", &n);
    while (n)
    {
        int choice;
        printf("\nEnter 1 to insert\nEnter 2 to CreateTwoList\nEnter 3 to display Odd list\nEnter 4 to display Even list\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int new_data;
            printf("\nEnter the data\n");
            scanf("%d", &new_data);
            head = insert(&head, &last, new_data);
            display(head);
            printf("\n");
            break;

        case 2:
            CreateTwoList(&head, &Odd, &even);
            break;

        case 3:
            display(Odd);
            printf("\n");
            break;
        case 4:
            display(even);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }
    return 0;
}