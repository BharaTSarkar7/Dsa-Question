#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int val)
{
    if ((!s.empty() && s.top()) < val || s.empty())
    {
        s.push(val);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, val);

    s.push(num);
}

void SortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    SortStack(s);

    solve(s, num);
}

int main(int argc, char *argv[])
{
    stack<int> st;
    int size;
    cout << "enter the size" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        st.push(data);
    }
    SortStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}