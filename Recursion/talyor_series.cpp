#include <bits/stdc++.h>
using namespace std;

double e(int m, int n)
{
    static double p = 1, f = 1;
    if (n == 0)
    {
        return 1;
    }
    double re = e(m, (n - 1));
    p = p * m;
    f = f * n;
    return re + p / f;
}

int main(int argc, char *argv[])
{
    double re;
    re = e(2, 15);
    cout << re << endl;
    return 0;
}