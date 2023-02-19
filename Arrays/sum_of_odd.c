#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(a) / sizeof(a[0]);
    int odd_sum = 0, i;
    for (i = 0; i < size; i++)
    {
        if (a[i] % 2 == 1)
        {
            odd_sum += a[i];
        }
    }
    printf("sum is %d", odd_sum);
    return 0;
}