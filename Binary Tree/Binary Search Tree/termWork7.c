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

struct bst_node *minNode(struct bst_node *root)
{
    struct bst_node *cur = root;
    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

struct bst_node *deletenode(struct bst_node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct bst_node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct bst_node *temp = root->right;
            free(root);
            return temp;
        }

        struct bst_node *temp = minNode(root->right);
        root->data = temp->data;
        int min = temp->data;
        root->right = deletenode(root->right, min);
    }
    return root;
}

int height(struct bst_node *root)
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

int searchnode(struct bst_node *root, int key)
{
    struct bst_node *temp_tree = root;
    while (temp_tree != NULL)
    {
        if (temp_tree->data > key)
        {
            temp_tree = temp_tree->left;
        }
        else if (temp_tree->data < key)
        {
            temp_tree = temp_tree->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int leafnodes(struct bst_node *root)
{
    static int count = 0;
    if (root != NULL)
    {
        leafnodes(root->left);
        if ((root->left == NULL) && (root->right == NULL))
        {
            count++;
        }
        leafnodes(root->right);
    }
    return count;
}

int totalNodes(struct bst_node *root)
{
    if (root == NULL)
        return 0;
    int r = totalNodes(root->right);
    int l = totalNodes(root->left);

    return 1 + l + r;
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
        printf("Enter 1 to insert\nEnter 2 to search\nEnter 3 to delete\nEnter 4 to find total leaf node\nEnter 5 to height of tree\nEnter 6 to find total no. of node in right of root\n");
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
            int se_key;
            printf("\nEnter the key to search\n");
            scanf("%d", &se_key);
            if (searchnode(root, se_key))
            {
                printf("Data is found\n");
            }
            else
            {
                printf("Data is not found\n");
            }
            break;

        case 3:
            int key;
            printf("\nEnter the key to delete\n");
            scanf("%d", &key);
            root = deletenode(root, key);
            break;

        case 4:
            printf("\nTotal No. of leaf nodes are %d\n", leafnodes(root));
            break;

        case 5:
            printf("Height of tree is %d\n", height(root));
            break;

        case 6:
            printf("Total no. of nodes at right side of root are %d\n", totalNodes(root));
            break;

        case 7:
            inoder_traversal(root);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        fflush(stdin);
        scanf("%d", &n);
    }

    return 0;
}