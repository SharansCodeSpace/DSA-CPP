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


void deleteBST(int data)
{
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
    else if (data < root->data)
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
    return 0;
}