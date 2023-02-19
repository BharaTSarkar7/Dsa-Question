#include <bits/stdc++.h>
using namespace std;

bool validParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
                {
                    st.pop();
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
    if (st.empty())
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