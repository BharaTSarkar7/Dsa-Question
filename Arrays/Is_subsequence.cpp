#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    string temp;
    int o = 0;
    for (int i = 0; i < t.length(); i++)
    {
        int flag = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (t[i] == s[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            temp[o++] = t[i];
        }
    }
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != temp[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main(int argc, char *argv[])
{
    if (isSubsequence("axc", "ahbgdc"))
    {
        /* code */
    }

    return 0;
}