#include <bits/stdc++.h>
using namespace std;

string move_a_char(string s, char key)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ros = move_a_char(s.substr(1), key);
    if (ch == key)
    {
        return (ros + ch);
    }
    return (ch + ros);
}

int main(int argc, char *argv[])
{
    string str;
    cout << "Enter a string" << endl;
    getline(cin, str);
    char ch;
    cout << "Enter a character to be moved" << endl;
    cin >> ch;
    cout << move_a_char(str, ch) << endl;
    return 0;
}