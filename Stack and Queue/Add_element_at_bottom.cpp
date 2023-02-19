#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int count, int val)
{
    if (count == 0) // if count is 0 it means it reaches the bottom of stack now store the val
    {
        st.push(val);
        return;
    }

    int num = st.top();  // Storing top element of stack for reuse after recursive call is done

    st.pop(); // removing top element for delete the middle element as count reaches middle element it should be top element

    // Recursive Call

    solve(st, count - 1, val);  // sending stack with top element removed and count decreased by 1 while it reaches  0 and same val

    st.push(num); // reattaching the removed element from stack while recursive call returns
}

void AddElement(stack<int> &s, int size)
{
    int val;
    cout << "Enter the element" << endl;
    cin >> val;
    int count = size;
    solve(s, count, val);
}

int main(int argc, char *argv[])
{
    stack<int> s;

    int size;
    cout << "enter the size" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        s.push(data);
    }
    AddElement(s, size);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}