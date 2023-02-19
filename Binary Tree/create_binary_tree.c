#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createTree(struct node *root)
{
    printf("enter the data\n");
    int new_data;
    scanf("%d", &new_data);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = new_data;
    root->left = NULL;
    root->right = NULL;
    if (new_data == -1)
    {
        return NULL;
    }

    printf("Enter the data for inserting at left of %d", new_data);
    root->left = createTree(root->left);
    printf("Enter the data for inserting at rigth of %d", new_data);
    root->right = createTree(root->right);
    return root;
}

void printPreorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);

    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = createTree(root);
    printPreorder(root);
    return 0;
}
// 1 2 3 -1 4 -1 -1 5 6 7 -1 8 -1 -1 9 -1 -1 -1