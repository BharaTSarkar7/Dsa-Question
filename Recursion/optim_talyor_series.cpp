#include <bits/stdc++.h>
using namespace std;

#define Cons 15

double e(int m, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return 1;
    }
    s = 1 + m * s / n;
    e(m, (n - 1));
    return s;
}

int main(int argc, char *argv[])
{
    double re = e(2, Cons);
    cout << re << endl;
    return 0;
}