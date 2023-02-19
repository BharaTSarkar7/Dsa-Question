#include <bits/stdc++.h>
using namespace std;
int poww(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return poww(m, n - 1) * m;
}

int main(int argc, char *argv[])
{
    int re;
    re = poww(2, 6);
    cout << re << endl;
    return 0;
}