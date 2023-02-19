#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a[] = {1, 1, 2};
    int size = sizeof(a) / sizeof(a[0]);
    int i, j, flag;
    for (i = 0; i < size; i++)
    {
        flag = 0;
        for (j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            size -= 1;
            for (int k = j; k < size; k++)
            {
                a[k] = a[k + 1];
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}