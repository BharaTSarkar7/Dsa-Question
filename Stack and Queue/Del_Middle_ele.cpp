#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int count, int sizeofstack)
{
    if (count == sizeofstack / 2)
    {
        s.pop();
        return;
    }

    int num = s.top(); // Storing top element of stack for reuse after recursive call is done

    s.pop(); // removing top element for delete the middle element as count reaches middle element it should be top element

    // Recursive Call

    solve(s, count + 1, sizeofstack); // sending stack with top element removed and count increased by 1 and same size of stack

    s.push(num); // reattaching the removed element from stack while recursive call returns
}

void MiddleElement(stack<int> &s, int sizeofstack)
{
    int count = 0;
    solve(s, count, sizeofstack);
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
    MiddleElement(s, size);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}