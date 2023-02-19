#include <stdio.h>
int main()
{
    int a[] = {1, 3, 2, 4, 5, 6}, b[] = {1, 2, 5, 3, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int i, j, o = 0, k = 0, c[m + n];
    for (i = 0; i < n; i++)
    {
        c[o++] = a[i];
        k++;
    }
    for (i = 0; i < m; i++)
    {
        int flag = 0;
        for (j = 0; j < k; j++)
        {
            if (b[i] == c[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            c[o++] = b[i];
        }
    }
    for (i = 0; i < o; i++)
    {
        printf("%d ", c[i]);
    }
}
