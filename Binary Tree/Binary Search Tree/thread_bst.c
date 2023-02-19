#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int isThreaded;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 0;
    return node;
}

void inorder(struct Node *root)
{
    struct Node *current = root;
    while (current != NULL)
    {
        if (current->isThreaded == 0)
        {
            while (current->left != NULL)
            {
                current = current->left;
            }
        }
        printf("%d ", current->data);
        if (current->isThreaded == 1)
        {
            current = current->right;
        }
        else
        {
            current = current->right;
        }
    }
}

int main()
{
    // Create root node
    struct Node *root = newNode(1);

    // Create left child
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Create right child
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Set threads
    root->left->right->right = root;
    root->left->right->isThreaded = 1;
    root->right->left->right = root->right;
    root->right->left->isThreaded = 1;
    root->right->right->right = NULL;
    root->right->right->isThreaded = 1;

    // Display tree in inorder traversal
    inorder(root);

    return 0;
}
