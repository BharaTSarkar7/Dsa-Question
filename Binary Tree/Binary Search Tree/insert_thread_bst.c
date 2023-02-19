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

struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        // Ignore duplicate values
        return node;
    }

    // Thread current node with in-order predecessor
    if (node->left != NULL && node->right == NULL)
    {
        node->right = node->left;
        node->isThreaded = 1;
    }

    return node;
}

int main()
{
    // Create root node
    struct Node *root = NULL;

    // Insert nodes into tree
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    // Display tree in inorder traversal
    inorder(root);

    return 0;
}
