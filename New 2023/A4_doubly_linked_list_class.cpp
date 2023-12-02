#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *head;

bool isEmpty()
{
    return head == NULL;
}

void traverse()
{
    Node *temp = head;
    cout << "My list: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertStart(int data)
{
    Node *ptr = new Node(data);
    ptr->next = head;
    if (!isEmpty())
        head->prev = ptr;
    head = ptr;
}

void insertEnd(int data)
{
    Node *ptr = new Node(data);
    if (isEmpty())
        head = ptr;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void insertAtIndex(int data, int index)
{
    Node *ptr = new Node(data);
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;
    temp->next->prev = ptr;
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
}

void deleteStart()
{
    if (isEmpty())
        cout << "List is empty!";
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void deleteEnd()
{
    if (isEmpty())
        cout << "List is empty!";
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
}

void deleteAtIndex(int index)
{
    if (isEmpty())
        cout << "List is empty!";
    else
    {
        struct Node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

int main()
{
    insertStart(10);
    insertStart(20);
    traverse();
    insertStart(30);
    insertEnd(40);
    traverse();
    insertAtIndex(34, 1);
    traverse();
    insertAtIndex(99, 2);
    traverse();
    deleteStart();
    traverse();
    deleteAtIndex(2);
    traverse();
    deleteEnd();
    return 0;
}
