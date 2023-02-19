#include <bits/stdc++.h>
using namespace std;
int dp[20];

int fib(int n)
{

    if (n <= 1)
    {
        dp[n] = n;
        return n;
    }
    else
    {
        if (dp[n - 1] == -1)
        {
            dp[n - 1] = fib(n - 1);
        }
        if (dp[n - 2] == -1)
        {
            dp[n - 2] = fib(n - 2);
        }
    }
    return dp[n - 1] + dp[n - 2];
}

int main(int argc, char *argv[])
{
    memset(dp, -1, sizeof(dp));
    cout << fib(7) << endl;
    return 0;
}

// Time Complexity is O(n)