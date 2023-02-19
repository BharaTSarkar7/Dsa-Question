#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    int sign = 1;
    if (dividend < 0 && divisor < 0)
    {
        sign = 1;
    }
    else if (dividend < 0 || divisor < 0)
    {
        sign = -1;
    }
    unsigned int end = abs(dividend);
    unsigned  int div= abs(divisor);

    long long int quotient = 0;
    while (end >= div)
    {
        end -= div;
        quotient++;
    }
    if (quotient > (pow(2, 31) - 1))
    {
        return (pow(2, 31) - 1);
    }
    else if (quotient < (pow(-2, 31)))
    {
        return pow(-2, 31);
    }
    else
    {
        return quotient * sign;
    }
}

int main(int argc, char *argv[])
{
    int a = -1, b = 1;
    cout << divide(a, b);
    return 0;
}
