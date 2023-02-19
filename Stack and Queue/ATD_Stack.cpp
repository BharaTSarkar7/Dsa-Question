#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int top;

public:
    // Constructors

    Stack()
    {
        this->size = INT_MAX;
        this->arr = new int(size);
        this->top = -1;
    }
    Stack(int Size)
    {
        this->size = Size;
        this->arr = new int(size);
        this->top = -1;
    }

    // Destructor

    ~Stack()
    {
        cout << endl;
        cout << "Memory Freed" << endl;
    }

    // Methods

    void push_Back(const int val);
    int pop();
    int peek();
    void display();
    bool isEmpty();
};

void ::Stack::push_Back(const int val)
{
    if (size - top > 1)
    {
        arr[++top] = val;
    }
    else
    {
        cerr << "Stack Overflow" << endl;
        exit(0);
    }
}

int ::Stack::pop()
{
    if (top > -1)
    {
        return --top;
    }
    else
    {
        cerr << "Stack UnderFlow" << endl;
        exit(0);
    }
}

int ::Stack::peek()
{
    if (top > -1)
    {
        return arr[top];
    }
    else
    {
        return -1;
    }
}

bool ::Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ::Stack::display()
{
    if (top > -1)
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }
}

int main(int argc, char *argv[])
{
    Stack check(5);
    check.push_Back(1);
    check.push_Back(2);
    check.push_Back(3);
    check.push_Back(4);
    check.push_Back(5);
    cout << "peak of stack: " << check.peek() << endl;
    check.display();
    return 0;
}