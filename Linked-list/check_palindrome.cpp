#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int new_data)
    {
        this->data = new_data;
        this->next = NULL;
    }
} * first;

Node *linker, *last;

void create(int limit)
{
    int new_data;
    cout << "enter the data" << endl;
    cin >> new_data;
    first->data = new_data;
    first->next = NULL;
    last = first;
    for (int i = 1; i < limit; i++)
    {
        cin >> new_data;
        linker = new Node(new_data);

        last->next = linker;
        last = last->next;
    }
}

bool check(vector<int> num)
{
    int sze = num.size();
    int start = 0, end = sze - 1;
    while (start <= end)
    {
        if (num[start] != num[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool Ispalin()
{
    vector<int> arr;
    linker = first;
    while (linker)
    {
        arr.push_back(linker->data);
        linker = linker->next;
    }
    return check(arr);
}

void display()
{
    last = first;
    while (last)
    {
        cout << last->data << " ";
        last = last->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    first = new Node();
    int n;
    cout << "enter the Number of nodes" << endl;
    cin >> n;
    create(n);
    if (Ispalin())
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}