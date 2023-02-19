#include <bits/stdc++.h>
using namespace std;

int fib(int n, int a = 0, int b = 1)
{
    if (n == 1)
    {
        return b;
    }
    return fib(n - 1, b, a + b);
}

int main(int argc, char *argv[])
{
    cout << fib(7) << endl;
    return 0;
}