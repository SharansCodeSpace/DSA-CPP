#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int list_size = 0;
struct Node *head = NULL;
struct Node *tail = NULL;

bool isEmpty()
{
    return list_size == 0;
}

void insertStart(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (isEmpty())
    {
        ptr->next = ptr;
        tail = ptr;
    }
    else
    {
        tail->next = ptr;
        ptr->next = head;
    }
    head = ptr;
    list_size++;
}

void insertMiddle(int data, int position)
{
    if (position > list_size)
        cout << "Invalid Position!" << endl;
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        struct Node *temp = head;
        for (int i = 0; i < position - 2; i++)
            temp = temp->next;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    list_size++;
}

void insertEnd(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (isEmpty())
        head = tail = ptr;
    else
    {
        tail->next = ptr;
        ptr->next = head;
        tail = ptr;
    }
    list_size++;
}

void traverse()
{
    if (isEmpty())
        cout << "List is empty!" << endl;
    else
    {
        struct Node *temp = head;
        cout << "List elements are: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

int deleteStart()
{
    int data = -1;
    if (isEmpty())
        cout << "List is Empty!" << endl;
    else
    {
        struct Node *temp = head;
        head = head->next;
        tail->next = head;
        data = temp->data;
        free(temp);
        list_size--;
    }
    return data;
}

int deleteMiddle(int position)
{
    int data = -1;
    if (isEmpty())
        cout << "List is Empty!" << endl;
    else if (position > list_size)
        cout << "Invalid Position!" << endl;
    else
    {
        struct Node *temp = head;
        for (int i = 0; i < position - 3; i++)
            temp = temp->next;
        data = temp->data;
        free(temp->next);
        temp->next = temp->next->next;
        list_size--;
    }
    return data;
}

int deleteEnd()
{
    int data = -1;
    if (isEmpty())
        cout << "List is Empty!" << endl;
    else
    {
        struct Node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next != tail);
        data = temp->data;
        temp->next = head;
        free(tail);
        tail = temp;
        list_size--;
    }
    return data;
}

int main()
{
    insertStart(10);
    traverse();
    insertStart(20);
    traverse();
    insertMiddle(30, 1);
    traverse();
    insertEnd(40);
    traverse();
    return 0;
}