#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_Node(int value)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void main()
{
    // Root node
    struct node *root = create_Node(4);
    struct node *p1 = create_Node(1);
    struct node *p2 = create_Node(6);
    struct node *p3 = create_Node(5);
    struct node *p4 = create_Node(2);

    //  Finally The tree looks like this:
    //       4
    //      / \
    //     1   6
    //    / \
    //   5   2

    // Linking root node with child nodes
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder traversal of given tree - ");
    preOrder(root);
    printf("\nPostorder traversal of given tree - ");
    postOrder(root);
    printf("\nInorder traversal of given tree - ");
    inOrder(root);
}