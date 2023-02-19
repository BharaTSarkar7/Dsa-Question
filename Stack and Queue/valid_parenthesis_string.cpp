#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string s)
{
    if (s == "*")
    {
        return true;
    }
    stack<char> check;
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '*')
        {
            if (!check.empty() && ch == '*' && check.top() == '*')
            {
                check.pop();
                continue;
            }
            else
            {
                if (ch == '*')
                {
                    flag = 1;
                }
                check.push(ch);
            }
        }
        else
        {
            if (!check.empty())
            {
                char top = check.top();
                if ((ch == ')' && top == '(') || (ch == '*' && top == '(') || (ch == '*' && top == '*') || (ch == ')' && top == '*'))
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (check.size() >= 1 && flag == 1)
    {
        return true;
    }
    else if (check.size() > 1 && check.top() == '(')
    {
        return false;
    }
    else if (!check.empty())
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
    string str;
    cout << "Enter the string" << endl;
    getline(cin, str);
    if (validParenthesis(str))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Not Valid" << endl;
    }
    return 0;
}