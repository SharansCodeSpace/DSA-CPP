#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *head = NULL;

bool isEmpty()
{
    return head == NULL;
}

void insertStart(int data)
{
    Node *ptr = new Node(data);
    if (isEmpty())
        ptr->next = NULL;
    else
        ptr->next = head;
    head = ptr;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *partition(int x)
{
    Node *small = new Node(-1);
    Node *large = new Node(-1);
    Node *small_head = small;
    Node *large_head = large;

    while (head != NULL)
    {
        if (head->data < x)
        {
            small->next = head;
            small = small->next;
            head = head->next;
            small->next = NULL;
        }
        else
        {
            large->next = head;
            large = large->next;
            head = head->next;
            large->next = NULL;
        }
    }
    small->next = large_head->next;
    return small_head->next;
}

int main()
{
    insertStart(2);
    insertStart(5);
    insertStart(2);
    insertStart(3);
    insertStart(4);
    insertStart(1);
    cout << "Before partition: ";
    printList(head);
    cout << endl;
    Node *partition_head = partition(3);
    cout << "After partition: ";
    printList(partition_head);
    cout << endl;
    return 0;
}