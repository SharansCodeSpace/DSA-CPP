#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int list_size = 0;
struct Node *head = NULL;

void insertStart(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (isEmpty())
        ptr->next = NULL;
    else
        ptr->next = head;
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
        if (position == 1)
        {
            ptr->next = head;
            head = ptr;
        }
        else
        {
            struct Node *temp = head;
            for (int i = 0; i < position - 2; i++)
                temp = temp->next;
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
    list_size++;
}

void insertEnd(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (isEmpty())
        head = ptr;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
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
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

bool isEmpty()
{
    return list_size == 0;
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
        if (position == 1)
        {
            head = head->next;
            data = temp->data;
            free(temp);
        }
        else
        {
            for (int i = 0; i < position - 3; i++)
                temp = temp->next;
            data = temp->data;
            free(temp->next);
            temp->next = temp->next->next;
        }
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
        while (temp->next->next != NULL)
            temp = temp->next;
        data = temp->next->data;
        free(temp->next);
        temp->next = NULL;
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