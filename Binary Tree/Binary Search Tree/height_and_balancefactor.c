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

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int LeftHeight = height(root->left);
        int RightHight = height(root->right);

        int max = (LeftHeight > RightHight) ? LeftHeight : RightHight;
        return max + 1;
    }
}

int balanceFactor(struct node *root)
{
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int res = abs(leftHeight - rightHeight);
    return res;
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
        printf("\nEnter 1 to insert\nEnter 2 to display\nEnter 3 to find Height\nEnter 4 to find balance factor\n");
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
            printf("Height of tree is %d\n", height(root));
            break;
        case 4:
            printf("Balance Factor of tree is %d\n", balanceFactor(root));
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        fflush(stdin);
        scanf("%d", &n);
    }

    return 0;
}