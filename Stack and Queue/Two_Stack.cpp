#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int top1, top2;
    int size;

public:
    // Constructor

    Stack()
    {
        this->size = INT_MAX;
        this->arr = new int(size);
        this->top1 = -1;
        this->top2 = size;
    }

    Stack(int Size)
    {
        this->size = Size;
        this->arr = new int(Size);
        this->top1 = -1;
        this->top2 = Size;
    }

    // Destructor

    ~Stack()
    {
        cout << "Memory Freed" << endl;
    }

    // Methods

    void push_1(int val);
    void push_2(int val);
    void pop_1();
    void pop_2();
    void display_1();
    void display_2();
};

void ::Stack::push_1(int val)
{
    if (top2 - top1 > 1)
    {
        arr[++top1] = val;
    }
    else
    {
        cout << "Stack OverFlow" << endl;
    }
}

void ::Stack::push_2(int val)
{
    if (top2 - top1 > 1)
    {
        arr[--top2] = val;
    }
    else
    {
        cout << "Stack OverFlow" << endl;
    }
}

void ::Stack::pop_1()
{
    if (top1 > -1)
    {
        --top1;
    }
    else
    {
        cout << "Stack UnderFlow";
    }
}

void ::Stack::pop_2()
{
    if (top2 < size)
    {
        ++top1;
    }
    else
    {
        cout << "Stack UnderFlow";
    }
}

void ::Stack::display_1()
{
    if (top1 > -1)
    {
        for (int i = top1; i >= 0; i--)
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

void ::Stack::display_2()
{
    if (top1 < size)
    {
        for (int i = top2; i < size; i++)
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

main(int argc, char *argv[])
{
    Stack s1(5);
    s1.push_1(1);
    s1.push_1(2);
    s1.push_1(3);
    s1.push_2(4);
    s1.push_2(5);
    s1.display_1();
    s1.display_2();
    return 0;
}