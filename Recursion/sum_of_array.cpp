#include <bits/stdc++.h>
using namespace std;

int sum_arr(int a[], int n)
{
    int sum = 0;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return a[0];
    }
    sum = a[0] + sum_arr(a + 1, n - 1);
    return sum;
}

int main(int argc, char *argv[])
{
    int a[]{1, 2, 3, 4, 5};
    int sum = sum_arr(a, 5);
    cout << sum << endl;
    return 0;
}