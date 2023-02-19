#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int new_data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = new_data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insertnode(struct node *root, int new_data)
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

struct node *rotateLeft(struct node *root)
{
    struct node *new_head = root->right;
    struct node *temp = new_head->left;

    new_head->left = root;
    root->right = temp;
    return new_head;
}

struct node *rotateRight(struct node *root)
{

    struct node *new_head = root->left;
    struct node *temp = new_head->right;

    new_head->right = root;
    root->left = temp;
    return new_head;
}

void inoder_traversal(struct node *root)
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
    struct node *root = NULL;
    int n;
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d", &n);
    while (n != 0)
    {
        int choice;
        printf("\nEnter 1 to insert\nEnter 2 to display\nEnter 3 to rotate left\nEnter 4 to rotate left\n");
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
        case 3:
            root = rotateLeft(root);
            printf("\nAfter the Rotate left\n");
            inoder_traversal(root);
            break;
        case 4:
            root = rotateRight(root);
            printf("\nAfter the Rotate right\n");
            inoder_traversal(root);
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        fflush(stdin);
        scanf("%d", &n);
    }

    return 0;
}