#include <bits/stdc++.h>
using namespace std;

void toh(int n, int s, int m, int e)
{
    if (n > 0)
    {
        toh(n - 1, s, e, m);
        cout << s << " moved to " << e << endl;
        toh(n - 1, m, s, e);
    }
}

int main(int argc, char *argv[])
{
    toh(3, 1, 2, 3);
    return 0;
}

// time complexity is O(2^n)