#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return sum(n - 1) + n;
}

int main(int argc, char *argv[])
{
    int re;
    re = sum(10);
    cout << re << endl;
    return 0;
}