#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(a) / sizeof(a[0]);
    int even_sum = 0, i;
    for (i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            even_sum += a[i];
        }
    }
    printf("sum is %d", even_sum);
    return 0;
}