#include <stdio.h>
int main()
{
    int a[] = {-1, 5, 6, -6, -2, 7};
    int j = 0;
    for (int i = 0; i < 6; i++)
    {
        if (a[i] > 0)
        {
            i++;
        }
        else
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j++;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}