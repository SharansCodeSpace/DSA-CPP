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

// Logic is that the inorder traversal of BST is in ascending order with no duplicate values...
int isBST(struct node *root)
{
    static struct node *previous = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (previous != NULL && root->data < previous->data)
            return 0;
        previous = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int search(struct node *root, int key)
{
    if (root == NULL)
        return -1;
    if (key == root->data)
        return root->data;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct node *insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("\nCannot insert...\n%d is already present in the BST..\n", key);
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    if (root == NULL)
    {
        struct node *new = create_Node(key);
        if (key < prev->data)
            prev->left = new;
        else
            prev->right = new;
    }
    printf("\n%d inserted into the BST...\n", key);
}

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *delete (struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = delete (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    //  Deletion when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
    return root;
}

void main()
{
    struct node *root = create_Node(5);
    struct node *p1 = create_Node(3);
    struct node *p2 = create_Node(6);
    struct node *p3 = create_Node(1);
    struct node *p4 = create_Node(4);

    //  Finally The tree looks like this:
    //       5
    //      / \
    //     3   6
    //    / \
    //   1   4

    // Linking root node with child nodes
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    int choice;
    printf("*****BINARY SEARCH TREES*****\n");
    printf("1 -> Check if the tree is binary search tree or not\n");
    printf("2 -> Insertion\n");
    printf("3 -> Deletion\n");
    printf("4 -> Preorder traversal\n");
    printf("5 -> Postorder traversal\n");
    printf("6 -> Inorder traversal\n");
    printf("7 -> Search for a tree element\n");
    printf("8 -> Exit\n");
    int data;
    do
    {
        printf("\nEnter your choice -> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isBST(root))
                printf("\nThe given tree is a BST...\n", isBST(root));
            else
                printf("\nThe given tree is not a BST...\n", isBST(root));
            break;
        case 2:
            printf("\nEnter data to be inserted: ");
            scanf("%d", &data);
            insert(root, data);
            break;
        case 3:
            printf("\nEnter data to be deleted: ");
            scanf("%d", &data);
            delete (root, data);
            printf("\n%d deleted from the BST...\n", data);
            break;
        case 4:
            printf("Preorder traversal of given BST - ");
            preOrder(root);
            printf("\n");
            break;
        case 5:
            printf("\nPostorder traversal of given BST - ");
            postOrder(root);
            printf("\n");
            break;
        case 6:
            printf("\nInorder traversal of given BST - ");
            inOrder(root);
            printf("\n");
            break;
        case 7:
            printf("\nEnter element to be searched: ");
            scanf("%d", &data);
            if (search(root, data) != -1)
                printf("\nSearch successful...\nElement found...\n");
            else
                printf("\nSearch unsuccessful...\nElement not found...\n");
            break;
        case 8:
            printf("\nThank you...\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice...\nEnter again...\n");
        }
    } while (1);
}