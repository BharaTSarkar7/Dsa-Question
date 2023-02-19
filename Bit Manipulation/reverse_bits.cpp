#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            num = num * 10 + s[i] - '0';
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
        }
    }
    return num;
}

int main(int argc, char *argv[])
{
    string s = "   -42";
    int k = myAtoi(s);
    cout << k << endl;
    return 0;
}