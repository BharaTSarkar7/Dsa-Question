#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void rotateSubArray(int arr[], int l, int r)
{
    int temp = arr[r];
    for (int j = r; j > l - 1; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[l] = temp;
}

void moveNegative(int arr[], int n)
{
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            last += 1;
            int temp = arr[i];
            arr[i] = arr[last];
            arr[last] = temp;
            if (i - last >= 2)
                rotateSubArray(arr, last + 1, i);
        }
    }
}

int main()
{
    int arr[50], n;
    printf("\nenter the number of elements: ");
    scanf("%d", &n);
    printf("\nenter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }
    moveNegative(arr, n);
    printArray(arr, n);
    return 0;
}
