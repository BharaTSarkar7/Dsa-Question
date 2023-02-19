#include <bits/stdc++.h>
using namespace std;

// void fun(int n)
// {
//     if (n > 0)
//     {

//         fun(n - 1);
//         cout << n << " ";     // for 3 it will print = 1 2 1 3 1 2 1
//         fun(n - 1);
//     }
// }

void fun(int n)
{
    if (n > 0)
    {

        fun(n - 1);
        fun(n - 1);
        cout << n << " "; // for 3 it will print = 1 1 2 1 1 2 3
    }
}

// void fun(int n)
// {
//     if (n > 0)
//     {

//         cout << n << " ";      for 3 it will print = 3 2 1 1 2 1 1
//         fun(n - 1);
//         fun(n - 1);
//     }
// }

int main(int argc, char *argv[])
{
    fun(3);
    return 0;
}

// TIME Complexity is O(2^n) wrost case
// Space complexity is O(n)