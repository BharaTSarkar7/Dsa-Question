#include <stdio.h>
#include <stdlib.h>

struct bst_node
{
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_node *createnode(int new_data)
{
    struct bst_node *newnode = (struct bst_node *)malloc(sizeof(struct bst_node));
    newnode->data = new_data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

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

struct bst_node *insertnode(struct bst_node *root, int new_data)
{
    if (root == NULL)
    {
        root = createnode(new_data);
    }
    else if (new_data < root->data)
    {
        root->left = insertnode(root->left, new_data);
    }
    else if (new_data > root->data)
    {
        root->right = insertnode(root->right, new_data);
    }
    else if (new_data == root->data)
    {
        printf("Error 0\n");
        exit(0);
    }
    return root;
}

int main()
{
    struct bst_node *root = NULL;
    int n;
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d", &n);
    while (n)
    {
        int choice;
        printf("Enter 1 to insert\nEnter 2 to display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int new_data;
            printf("\nEnter the data\n");
            scanf("%d", &new_data);
            root = insertnode(root, new_data);
            break;

        case 2:
            inoder_traversal(root);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }

    return 0;
}