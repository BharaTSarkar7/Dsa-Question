#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string s)
{
    if (s == "*")
    {
        return true;
    }
    stack<int> check_open, check_ast;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (!check_open.empty())
            {
                check_open.pop();
            }
            else if (!check_ast.empty())
            {
                check_ast.pop();
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '(')
        {
            check_open.push(i);
        }
        else
        {
            check_ast.push(i);
        }
    }
    while (!check_open.empty() && !check_ast.empty())
    {
        if (check_open.top() > check_ast.top()) 
        {
            return false;
        }
        check_open.pop();
        check_ast.pop();
    }
    if (!check_open.empty())
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