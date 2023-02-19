// a person can climb 1 or 2 stair at a time ,so in how many ways he can climb n stair from start

#include <bits/stdc++.h>
using namespace std;

int stairs(int n)
{
    if (n < 0)

        return 0;

    if (n == 0)
        return 1;

    return stairs(n - 1) + stairs(n - 2);
}

int main(int argc, char *argv[])
{
    cout << stairs(5) << endl;
    return 0;
}