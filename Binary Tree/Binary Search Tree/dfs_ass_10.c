#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct stackNode
{
    struct treeNode *t;
    struct stackNode *next;
};

void push(struct stackNode **top_ref, struct treeNode *temp)
{
    struct stackNode *new_treeNode = (struct stackNode *)malloc(sizeof(struct stackNode));

    if (new_treeNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }
    new_treeNode->t = temp;
    new_treeNode->next = (*top_ref);
    (*top_ref) = new_treeNode;
}

int isEmpty(struct stackNode *top)
{
    return (top == NULL) ? 1 : 0;
}

struct treeNode *pop(struct stackNode **top_ref)
{
    struct treeNode *res;
    struct stackNode *top;
    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

void DepthForSearch(struct treeNode *root)
{
    struct treeNode *current = root;
    struct stackNode *s = NULL;
    int counter = 0;

    while (!counter)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                counter = 1;
        }
    }
}

struct treeNode *createnode(int new_data)
{
    struct treeNode *newnode = (struct treeNode *)malloc(sizeof(struct treeNode));
    newnode->data = new_data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct treeNode *insertnode(struct treeNode *root, int new_data)
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
    struct treeNode *root = NULL;
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
            DepthForSearch(root);
            printf("\n");
            break;
        }
        printf("\nEnter 1 to continue or 0 to exit\n");
        scanf("%d", &n);
    }

    return 0;
}