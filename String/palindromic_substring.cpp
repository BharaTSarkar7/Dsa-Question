#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

void sub_palin(string &s)
{
    int j = 0, o = 0;
    for (int i = 0; i < s.length(); i++)
    {
        j = i;
        o = 0;
        while (s[j] != ' ')
        {
            j++;
            o++;
        }
        string ss = s.substr(i, o);
        if (ss.length() > 1)
        {
            if (ispalindrome(ss))
            {
                for (int k = i; k < j; k++)
                {
                    s[k] = '*';
                }
            }
        }
        i = j;
    }
    cout << s;
}

int main(int argc, char *argv[])
{
    string s = "bob has a radar plane";
    sub_palin(s);
    return 0;
}