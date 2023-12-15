#include <bits/stdc++.h>
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

void inorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
 
    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorder(Node* root)
{
    stack<Node*> s;
    s.push(root);
 
    while (s.empty() == false) {
        Node *curr = s.top();
        cout << curr->data << " ";
        s.pop();
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}

void postorder(Node* root)
{
    stack<Node*> s;
    s.push(root);
 
    while (s.empty() == false) {
        Node *curr = s.top();
        if (curr->right)
            s.push(curr->right);    
        if (curr->left)
            s.push(curr->left);
        cout << curr->data << " ";
        s.pop();
    }
}

int main()
{
    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(11);
    root->right->right = new Node(15);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    return 0;
}