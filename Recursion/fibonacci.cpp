#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[])
{
    cout << fib(6) << endl;
    return 0;
}

// Time complexity is O(2^n)