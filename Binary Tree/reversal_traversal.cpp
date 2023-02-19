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

void printPreorder(node *root)
{
    if (root == NULL)
        return;

    /* first print data of node */
    cout << root->data << " ";
    /* then recur on left subtree */
    printPreorder(root->left);

    /* now recur on right subtree */
    printPreorder(root->right);
}

int main(int argc, char *argv[])
{
    node *root = NULL;
    root = createTree(root);
    printPreorder(root);
    return 0;
}