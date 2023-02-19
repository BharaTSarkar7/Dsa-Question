#include <stdio.h>
#include <stdlib.h>

struct Node
{

    struct Node *next;
    int data;
    struct Node *prev;
};

struct Node *head = NULL;

void push(int data)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->data = data;
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}

void pop()
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL)
    {
        printf("Stack UnderFlow\n");
        exit(0);
    }
    else if (head->next == NULL && head->prev == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void display()
{
    struct Node *temp = head;
    if (head != NULL)
    {
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    pop();
    pop();
    display();
    return 0;
}