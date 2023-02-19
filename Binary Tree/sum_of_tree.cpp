#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor
    TreeNode()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int new_data)
    {
        this->data = new_data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root)
{
    int new_data;
    cout << "Enter the data" << endl;
    cin >> new_data;
    root = new TreeNode(new_data);
    if (new_data == -1)
    {
        return NULL;
    }
    cout << "Enter the data to insert at left of " << new_data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to insert at right of " << new_data << endl;
    root->right = buildTree(root->right);
    return root;
}

int sum_of_tree(TreeNode *root)
{
    static int sum = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        sum += temp->data;
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    TreeNode *root = NULL;
    root = buildTree(root);
    int sum = sum_of_tree(root);
    cout << "Sum of tree is " << sum << endl;
    return 0;
}