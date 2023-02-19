#include <bits/stdc++.h>
using namespace std;

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;

    // Constructor
    treenode(int new_data)
    {
        this->data = new_data;
        this->left = NULL;
        this->right = NULL;
    }
};

treenode *BuildTree(treenode *root)
{
    int new_data;
    cout << "enter the data" << endl;
    cin >> new_data;
    root = new treenode(new_data);
    if (new_data == -1)
    {
        return NULL;
    }
    cout << "Enter the data for inserting at left of " << new_data << " node" << endl;
    root->left = BuildTree(root->left);
    cout << "Enter the data for inserting at right of " << new_data << " node" << endl;
    root->right = BuildTree(root->right);
    return root;
}

vector<vector<int>> zigziglevelorder(treenode *root)
{
    vector<vector<int>> ans;
    queue<treenode *> q;
    q.push(root);
    int i = 0;
    while (!q.empty())
    {
        vector<int> temp;
        i++;
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            treenode *tmp = q.front();
            temp.push_back(tmp->data);
            q.pop();
            if (tmp->left)
            {
                q.push(tmp->left);
            }
            if (tmp->right)
            {
                q.push(tmp->right);
            }
        }
        if (i % 2 == 0)
        {
            reverse(temp.begin(), temp.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    treenode *root = NULL;
    root = BuildTree(root);
    vector<vector<int>> sol;
    sol = zigziglevelorder(root);
    for (vector<int> vec : sol)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}