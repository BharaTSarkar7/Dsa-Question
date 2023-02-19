#include <bits/stdc++.h>
using namespace std;

int max_in(int a[], int n)
{
    static int max = INT_MIN;
    if (n < 0)
    {
        return 0;
    }
    if (max < a[n])
    {
        max = a[n];
    }
    max_in(a, n - 1);

    return max;
}

int min_in(int a[], int n)
{
    static int min = INT_MAX;
    if (n < 0)
    {
        return 0;
    }
    if (min > a[n])
    {
        min = a[n];
    }
    min_in(a, n - 1);

    return min;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_ = max_in(a, n - 1);
    int min_ = min_in(a, n - 1);

    cout << "Minimum value is " << min_ << endl;
    cout << "maximum value is " << max_ << endl;

    return 0;
}