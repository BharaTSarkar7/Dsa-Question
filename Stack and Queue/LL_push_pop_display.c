#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (rear == NULL || front == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        rear = front = newNode;
    }

    else
    {
        newNode->data = data;
        newNode->next = NULL;
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

void dequeue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue UnderFlow\n");
        exit(0);
    }
    else
    {
        temp = front;
        front = front->next;
        front->prev = NULL;
        temp->next = NULL;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(temp);
    }
}

void display()
{
    struct Node *temp = front;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    display();
}