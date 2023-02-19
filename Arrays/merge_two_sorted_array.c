#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a = (int *)malloc(9 * sizeof(int));
    for (int j = 0; j < 9; j++)
    {
        scanf("%d", (a + j));
    }

    int b[] = {1, 2, 2};
    int size = sizeof(b) / sizeof(b[0]);
    int i = 6, j = 0;
    a = (int *)realloc(a, sizeof(int) * i);
    // while (size)
    // {
    //     a[i++] = b[j++];
    //     size--;
    // }
    int size2 = sizeof(a) / sizeof(a[0]);
    printf("%d ", size2);
    for (i = 0; i < size2; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
