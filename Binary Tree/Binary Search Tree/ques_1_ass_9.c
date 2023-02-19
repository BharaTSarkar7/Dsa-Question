#include <stdio.h>
#include <stdlib.h>

struct bst_node
{
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

void inoder_traversal(struct bst_node *root)
{
    if (root == NULL)
    {
        return;
    }
    inoder_traversal(root->left);
    printf("%d ", root->data);
    inoder_traversal(root->right);
}

int main()
{
    struct bst_node *root = NULL;
    root->data = 100;
    root->left->data = 20;
    root->right->data = 200;
    root->left->left->data = 10;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->data = 30;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->data = 150;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->data = 300;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    printf("Inorder Traversal: ");
    inoder_traversal(root);
    printf("\n");
    return 0;
}