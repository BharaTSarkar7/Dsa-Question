#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int top = -1;

void push(const int val)
{
    if (MAX - top > 1)
    {
        arr[++top] = val;
    }
    else
    {
        printf("Stack OverFlow\n");
        exit(0);
    }
}

void display()
{
    if (top > -1)
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", arr[i]);
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
    return 0;
}