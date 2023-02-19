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
};

Node *linker, *last;

void create(Node *list, int limit)
{
    int new_data;
    cout << "enter the data" << endl;
    cin >> new_data;
    list->data = new_data;
    list->next = NULL;
    last = list;
    for (int i = 1; i < limit; i++)
    {
        cin >> new_data;
        linker = new Node(new_data);

        last->next = linker;
        last = last->next;
    }
}

Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

void sortList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *mid = middle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    Node *res = merge(left, right);

    return res;
}

void display(Node *list)
{
    linker = list;
    while (linker != NULL)
    {
        cout << linker->data << " ";
        linker = linker->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Node *first = new Node();
    int n;
    cout << "enter the Number of nodes for first list" << endl;
    cin >> n;
    create(first, n);
    first = sortList(first);
    cout << first->data << endl;
    return 0;
}