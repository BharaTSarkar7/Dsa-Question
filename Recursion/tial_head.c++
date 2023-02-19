#include <iostream>
using namespace std;

void fun(int x)
{
    if (x > 0)
    {
        fun(x - 1); // Head recursion
        cout << x << ' ';   // Output = 1 2 3 4 5
    }
}


// void fun(int x)
// {
//     if (x > 0)
//     {
//         cout << x << ' ';   // Output = 5 4 3 2 1
//         fun(x - 1); // tail recursion
//     }
// }

int main()
{
    int n = 5;
    fun(n);
}