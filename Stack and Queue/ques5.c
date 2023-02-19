#include <stdio.h>
#include <stdlib.h>

void **rear = NULL, **front = NULL;

void enqueue(int data)
{
    if (rear == NULL || front == NULL)
    {
        front = rear = (void *)calloc(2, sizeof(void *));
        rear[1] = NULL;
    }
    else
    {
        rear[1] = (void *)calloc(2, sizeof(void *));
        rear = rear[1];
    }
    rear[0] = (int *)malloc(sizeof(int));
    rear[0] = data;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue UnderFlow\n");
        exit(0);
    }
    else
    {
        void **temp = front;
        front = front[1];
        temp[1] = NULL;
        free(temp);
    }
}

void display()
{
    void **temp = front;
    while (temp)
    {
        printf("%d ", ((int)(temp[0])));
        temp = temp[1];
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