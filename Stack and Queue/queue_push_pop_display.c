#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue_array[MAX];
int rear = -1;
int front = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue_array[rear] = data;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
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
    dequeue();
    display();
    return 0;
}