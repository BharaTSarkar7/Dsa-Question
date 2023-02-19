#include <bits/stdc++.h>
using namespace std;

string Remove(string &my_str)
{
    string temp;
    for (int i = 0; i < my_str.size(); ++i)
    {
        if (my_str[i] >= 'a' && my_str[i] <= 'z' || my_str[i] >= '0' && my_str[i] <= '9')
        {
            temp = temp + my_str[i];
        }
    }
    my_str = temp;
    return my_str;
}

string Reverse(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
    return str;
}

bool Ispalindrome(string &s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    Remove(s);
    string s2 = s;
    Reverse(s2);
    if (s.compare(s2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    string str = "0P0";
    if (Ispalindrome(str))
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}