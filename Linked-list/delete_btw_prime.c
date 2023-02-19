#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int is_prime(int data)
{
    for (int i = 2; i < data; i++)
    {
        if (data % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

struct node *del_btw_primes(struct node **head_ref)
{
    struct node *ptr_1 = *head_ref;
    while (ptr_1 != NULL)
    {
        if (is_prime(ptr_1->data))
        {
            break;
        }
        ptr_1 = ptr_1->next;
    }
    struct node *ptr_2 = ptr_1->next;
    while (ptr_2 != NULL)
    {
        if (is_prime(ptr_2->data))
        {
            break;
        }
        ptr_2 = ptr_2->next;
    }
    struct node *ptr_3 = ptr_1->next;
    while (ptr_3 != ptr_2)
    {
        struct node *temp = ptr_3;
        ptr_3 = ptr_3->next;
        temp->next = NULL;
        free(temp);
    }
    ptr_1->next = ptr_3;
    return *head_ref;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 3;
    head->next->data = 4;
    head->next->next->data = 6;
    head->next->next->next->data = 9;
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;
    head = del_btw_primes(&head);
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}