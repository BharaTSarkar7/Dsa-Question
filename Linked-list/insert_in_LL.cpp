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
    Node(int New_data)
    {
        this->data = New_data;
        this->next = NULL;
    }
} * first;

Node *last, *temp;

void create(const int limit)
{
    int new_data, i;
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
        for (i = 1; i < limit; i++)
        {
            temp = new Node();
            cin >> new_data;
            temp->data = new_data;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
        }
    }
}

int Length()
{
    int count = 0;
    temp = first;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert(int poistion, const int insert_data)
{
    int index = 1;
    Node *nodeToinsert = new Node();
    if (poistion == 1)
    {
        nodeToinsert->data = insert_data;
        nodeToinsert->next = first;
        first = nodeToinsert;
    }
    else if (poistion == Length())
    {
        nodeToinsert->data = insert_data;
        nodeToinsert->next = NULL;
        last->next = nodeToinsert;
        last = nodeToinsert;
    }
    else
    {
        temp = first;

        nodeToinsert->data = insert_data;
        while (index < poistion - 1)
        {
            temp = temp->next;
            index++;
        }
        nodeToinsert->next = temp->next;
        temp->next = nodeToinsert;
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

int main()
{
    int n;
    first = new Node();
    cout << "enter the limit" << endl;
    cin >> n;
    create(n);
    display();
    cout << "after insert a node" << endl;
    insert(1, 6);
    display();
}