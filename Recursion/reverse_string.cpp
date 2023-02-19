#include <bits/stdc++.h>
using namespace std;

void revStr(string s)
{
    if (s.length() > 0)
    {
        revStr(s.substr(1));
        cout << s[0];
    }
}

int main(int argc, char *argv[])
{
    revStr("Santosh");
    return 0;
}