#include <stdio.h>
#define MAX 100
int insert(int *b, int length)
{
    int i, new_data;
    printf("Eneter the data to insert\n");
    scanf("%d", &new_data);
    if (length <= 0)
    {
        i = 0;
        b[i] = new_data;
        return ++length;
    }
    else
    {
        int posi;

        printf("Enter the poistion to Insert data\n");
        scanf("%d", &posi);
        length++;
        for (i = length - 1; i >= posi - 1; i--)
        {
            b[i] = b[i - 1];
        }
        b[posi - 1] = new_data;
        return length;
    }
}

int Delete(int *b, int length)
{
    if (length <= 1)
    {
        return --length;
    }
    int posi;
    printf("Enter the positon to delete");
    scanf("%d", &posi);
    if (posi > length)
    {
        length = -1;
        return length;
    }
    else
    {
        for (int i = posi - 1; i < length; i++)
        {
            b[i] = b[i + 1];
        }
        return --length;
    }
}

int Search(int *b, int length)
{
    int flag = 0, tosearch;
    printf("Enter the number to search\n");
    scanf("%d", &tosearch);

    for (int i = 0; i < length; i++)
    {
        if (b[i] == tosearch)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void display(int *b, int length)
{
    if (length == 0)
    {
        printf("There is No element\n");
    }
    else if (length == -1)
    {
        printf("Operation cant be perform\n");
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            printf("%d ", b[i]);
        }
    }
    printf("\n");
}

int main()
{
    int a[MAX] = {1, 2, 3, 4, 5};
    display(a, 5);
    int size, key;
    printf("Enter 1 To perform insert Function\nEnter 2 To perform delete Function\nEnter 3 To perform search Function\nEnter 4 To perform display Function\n");
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        size = insert(a, 5);
        display(a, size);
        break;
    case 2:
        size = Delete(a, 5);
        display(a, size);
        break;
    case 3:
        size = Search(a, 5);
        if (size == 1)
        {
            printf("Element Found");
        }
        else
        {
            printf("Not Element Found");
        }
        break;
    case 4:
        display(a, 5);
        break;
    }
    return 0;
}
