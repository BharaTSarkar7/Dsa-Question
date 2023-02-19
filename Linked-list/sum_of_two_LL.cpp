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
};

Node *last, *temp;

// <------------------------- CREATE FUNCTION ---------------------------------->

void create(Node *list, const int limit)
{
    int new_data, i;
    if (list == NULL)
    {
        cout << "error";
        exit(0);
    }
    else
    {
        cin >> new_data;
        list->data = new_data;
        list->next = NULL;
        last = list;
        for (i = 1; i < limit; i++)
        {
            cin >> new_data;
            temp = new Node(new_data);
            last->next = temp;
            last = last->next;
        }
    }
}

Node *Reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = Reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

void display(Node *list)
{
    Node *t2 = list;
    while (t2)
    {
        cout << t2->data << " ";
        t2 = t2->next;
    }
    cout << endl;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    int sum1 = 0, sum2 = 0, tot = 0;

    l1 = Reverse(l1);

    l2 = Reverse(l2);
    Node *l3 = NULL;
    while (l1)
    {
        sum1 = sum1 * 10 + l1->data;
        l1 = l1->next;
    }
    while (l2)
    {
        sum2 = sum2 * 10 + l2->data;
        l2 = l2->next;
    }
    tot = sum1 + sum2;
    int rem = tot % 10;
    tot /= 10;
    Node *l4 = new Node(rem);
    Node *t = l4;
    while (tot != 0)
    {
        rem = tot % 10;
        tot /= 10;
        l3 = new Node(rem);
        t->next = l3;
        t = t->next;
    }
    return l4;
}

int main(int argc, char *argv[])
{
    int n;
    Node *first = new Node();
    Node *second = new Node();
    cout << "enter the limit" << endl;
    cin >> n;
    create(first, n);
    cout << "enter the limit" << endl;
    cin >> n;
    create(second, n);
    Node *linker = addTwoNumbers(first, second);
    while (linker)
    {
        cout << linker->data << " ";
        linker = linker->next;
    }
}