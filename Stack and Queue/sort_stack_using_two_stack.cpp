#include <bits/stdc++.h>
using namespace std;

stack<int> Sort(stack<int> &s)
{
    stack<int> temp;
    while (!s.empty())
    {
        int num = s.top();
        s.pop();

        while (!temp.empty() && temp.top() > num)
        {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(num);
    }
    return temp;
}

int main(int argc, char *argv[])
{
    stack<int> stack;
    int size;
    cout << "enter the size" << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        stack.push(data);
    }
    stack = Sort(stack);
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}