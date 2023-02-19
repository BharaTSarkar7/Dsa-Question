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

// <------------------------- CREATE FUNCTION ---------------------------------->

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

// <------------------------- LENGTH FUNCTION ---------------------------------->

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

// <------------------------- DELETE FUNCTION ---------------------------------->

void Delete(int poistion)
{
    if (poistion >= 1 && poistion <= Length())
    {
        int i = 0;
        Node *todelete = first;
        if (poistion == 1)
        {
            first = todelete->next;
            todelete = NULL;
        }
        else if (poistion == Length())
        {
            while (i != poistion - 1)
            {
                temp = todelete;
                todelete = todelete->next;
                i++;
            }
            temp->next = NULL;
            last = temp;
            todelete->next = NULL;
        }

        else
        {
            while (i != poistion - 1)
            {
                temp = todelete;
                todelete = todelete->next;
                i++;
            }
            temp->next = todelete->next;
            last = temp;
            todelete->next = NULL;
        }
    }
}

// <------------------------- INSERT FUNCTION ---------------------------------->

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

// <------------------------- Display Function ---------------------------------->

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

// <-------------------------- MAIN SECTION ------------------------------------>

int main(int argc, char *argv[])
{
    int n;
    first = new Node();
    cout << "enter the limit" << endl;
    cin >> n;
    create(n);
    display();
    Delete(5);
    cout << "after deleting a node" << endl;
    display();
    cout << "after insert a node" << endl;
    insert(1, 6);
    display();
    return 0;
}