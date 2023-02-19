// Create linked list using cpp

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
} * first;

Node *temp, *last;
void create(int limit)
{
    int new_data, index = 1;
    if (first == NULL)
    {
        cout << "error";
        exit(0);
    }
    else
    {
        cin >> new_data;
        first->data = new_data;
        first->next = NULL;
        last = first;
        for (index = 1; index < limit; index++)
        {
            cin >> new_data;
            temp = new Node(new_data);
            temp->next = NULL;
            last->next = temp;
            last = last->next;
        }
    }
}

void display()
{
    temp = first;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    int n;
    first = new Node();
    cout << "enter the limit" << endl;
    cin >> n;
    create(n);
    display();

    return 0;
}