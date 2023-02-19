#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a[]{1, 2, 3, 4, 5, 7, 6}, b[] = {5, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int i, j, o = 0, c[m + n];
    for (i = 0; i < n; i++)
    {
        int flag = 0;
        for (j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            c[o++] = a[i];
        }
    }
    for (i = 0; i < o; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}