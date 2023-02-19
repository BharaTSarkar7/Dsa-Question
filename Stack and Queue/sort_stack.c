#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top = -1;

void push(int *arr, const int val)
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

void pop()
{
    if (top > -1)
    {
        --top;
    }
    else
    {
        printf("Stack UnderFlow\n");
        exit(0);
    }
}

int Top(int *arr)
{
    if (top <= -1)
    {
        printf("Stack is empty\n");
        exit(0);
    }
    return arr[top];
}

int empty()
{
    if (top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sortedInsert(int *arr, int x)
{
    if (empty() )
    {
        push(arr, x);
    }
    else
    {
        int temp = Top(arr);
        pop();
        sortedInsert(arr, x);
        push(arr, temp);
    }
}

void sortstack(int *arr)
{
    if (!empty())
    {
        int x = Top(arr);
        pop();

        sortstack(arr);
        sortedInsert(arr, x);
    }
}

void display(int arr[])
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
    int arr[MAX];
    push(arr, 2);
    push(arr, 5);
    push(arr, 3);
    push(arr, 4);
    push(arr, 1);
    display(arr);
    sortstack(arr);
    display(arr);
    return 0;
}