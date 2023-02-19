#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    // Constructor
    node(int new_data)
    {
        this->data = new_data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree(node *root)
{
    int new_data;
    cout << "Enter the data" << endl;
    cin >> new_data;
    root = new node(new_data);
    if (new_data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting at left of " << new_data << " node" << endl;
    root->left = createTree(root->left);
    cout << "Enter the data for inserting at right of " << new_data << " node" << endl;
    root->right = createTree(root->right);
    return root;
}

int count_node(node *root)
{
    int count = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }

        if (temp->left->left == NULL && temp->left->right == NULL)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    node *root = NULL;
    root = createTree(root);
    int count = count_node(root);
    cout << "total leaf node " << count << endl;
    return 0;
}