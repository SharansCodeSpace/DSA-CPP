#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *root = NULL;

Node *deleteBST(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (root->data > data)
    {
        root->left = deleteBST(root->left, data);
        return root;
    }
    else if (root->data < data)
    {
        root->right = deleteBST(root->right, data);
        return root;
    }

    if (root->left == NULL)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }
    else
    {

        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;

        delete succ;
        return root;
    }
}

Node *insertRec(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    else if (data < root->data)
        root->left = insertRec(root->left, data);
    else if (data > root->data)
        root->right = insertRec(root->right, data);

    return root;
}

void insertBST(int data)
{
    root = insertRec(root, data);
}

void inorder(Node *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{
    insertBST(10);
    insertBST(5);
    insertBST(13);
    insertBST(3);
    inorder(root);
    cout << endl;
    deleteBST(root, 5);
    inorder(root);
    return 0;
}