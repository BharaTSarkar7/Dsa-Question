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

void printLevelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    node *root = NULL;
    root = createTree(root);
    printLevelorder(root);
    return 0;
}