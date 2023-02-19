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

void CreateTwoList(struct node **head_ref, struct node **neg, struct node **pos)
{
    struct node *neg_temp = NULL;
    struct node *pos_temp = NULL;
    while ((*head_ref) != NULL)
    {
        if ((*head_ref)->data < 0)
        {
            struct node *sepnode = (*head_ref);
            (*head_ref) = (*head_ref)->next;
            sepnode->next = NULL;
            if ((*neg) == NULL)
            {
                (*neg) = neg_temp = sepnode;
            }
            else
            {
                neg_temp->next = sepnode;
                neg_temp = neg_temp->next;
            }
        }
        if ((*head_ref)->data >= 0)
        {
            struct node *sepnode = (*head_ref);
            (*head_ref) = (*head_ref)->next;
            sepnode->next = NULL;
            if ((*pos) == NULL)
            {
                (*pos) = pos_temp = sepnode;
            }
            else
            {
                pos_temp->next = sepnode;
                pos_temp = pos_temp->next;
            }
        }
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
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *negative = NULL;
    struct node *positive = NULL;
    int n;
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d", &n);
    while (n)
    {
        int choice;
        printf("\nEnter 1 to insert\nEnter 2 to CreateTwoList\nEnter 3 to display Negative list\nEnter 4 to display Positive list\n");
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
            CreateTwoList(&head, &negative, &positive);
            break;

        case 3:
            display(negative);
            printf("\n");
            break;
        case 4:
            display(positive);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }
    return 0;
}

// i will create two fyunction one for positive and one for negative if the previous node will differnet then the prev node linked to next node then it will search fo it;
