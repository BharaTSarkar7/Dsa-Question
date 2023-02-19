#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct bst_node
{
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_node **createqueue(int *front, int *rear)
{
    struct bst_node **queue = (struct bst_node **)malloc(sizeof(struct bst_node *) * MAX);

    *front = *rear = 0;
    return queue;
}

void enqueue(struct bst_node **queue, int *rear, struct bst_node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

struct bst_node *dequeue(struct bst_node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

struct bst_node *createnode(int new_data)
{
    struct bst_node *newnode = (struct bst_node *)malloc(sizeof(struct bst_node));
    newnode->data = new_data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
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

void BreadthForSearch(struct bst_node *root)
{
    int front, rear;
    struct bst_node **queue = createqueue(&front, &rear);
    struct bst_node *temp = root;
    while (temp)
    {
        printf("%d ", temp->data);

        if (temp->left)
        {
            enqueue(queue, &rear, temp->left);
        }
        if (temp->right)
        {
            enqueue(queue, &rear, temp->right);
        }
        temp = dequeue(queue, &front);
    }
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
            BreadthForSearch(root);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }

    return 0;
}