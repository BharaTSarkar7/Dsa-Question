#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    set<char> check;
    set<char>::iterator i;
    for (int j = 0; j < s.length(); j++)
    {
        check.insert(s[j]);
    }
    s.clear();
    for (i = check.begin(); i != check.end(); i++)
    {
        s.push_back(*i);
    }
    return s;
}

int main(int argc, char *argv[])
{
    string s = "cbacdcbc";
    cout << removeDuplicateLetters(s) << endl;
    return 0;
}