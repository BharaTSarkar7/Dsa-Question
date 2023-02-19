#include <stdio.h>
#include <stdlib.h>

void insert(int *arr, int n)
{
    int new_data;
    printf("Enter the element\n");
    scanf("%d", &new_data);
    *(arr + n) = new_data;
}

int Delete(int n)
{
    return --n;
}

void Search(int *arr, int n)
{
    int val, flag = 0;
    printf("Enter the data to search\n");
    scanf("%d", &val);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == val)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Data found\n");
    }
    else
    {
        printf("Data Not found\n");
    }
}

void display(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int *arr = (int *)malloc(sizeof(int));
    int check, ch, ch2, n = 1;
    do
    {
        insert(arr, n);
        n++;
        arr = (int *)realloc(arr, sizeof(int) * n);
        printf("Press 1 to contiune or 0 to end\n");
        fflush(stdin);
        scanf("%d", &ch);
    } while (ch != 0);
    printf("Press 1 to Perform insertion\nPress 2 to Perform deletion\nPress 3 to Perform Search\nPress 4 to Perform display\n");
    scanf("%d", &check);
    switch (check)
    {
    case 1:
        do
        {
            insert(arr, n);
            n++;
            arr = (int *)realloc(arr, sizeof(int) * n);
            printf("Press 1 to contiune or 0 to end\n");
            fflush(stdin);
            scanf("%d", &ch);
        } while (ch != 0);
        display(arr, n);
        break;
    case 2:
        do
        {
            n = Delete(n);
            arr = (int *)realloc(arr, sizeof(int) * n);
            printf("Press 1 to contiune or 0 to end\n");
            fflush(stdin);
            scanf("%d", &ch);
        } while (ch != 0);
        printf("\nAfter Delete\n");
        display(arr, n);
        break;
    case 3:
        Search(arr, n);
        break;
    case 4:
        display(arr, n);
        break;
    }
    return 0;
}